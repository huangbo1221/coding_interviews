#include<iostream>
#include<vector>
using namespace std;

#define datatype int

void mySwap(vector<datatype>& vec, int index1, int index2) {
	datatype tmp = vec[index1];
	vec[index1] = vec[index2];
	vec[index2] = tmp;
}

void bubbleArrange(vector<datatype>& vec) {//冒泡排序
	int length = vec.size();
	if (length == 0)
		return;
	for (int i = 0; i < length-1 ;++i) {
		int tmp = 0;
		for (int j = 0 ; j < length -i- 1; ++j) {
			if (vec[j] > vec[j+1]) {
				mySwap(vec, j, j + 1);
			}
		}
	}
}

void selectArrange(vector<datatype>& vec) {//简单选择排序，交换的次数明显变少
	int length = vec.size();
	if (length == 0)
		return ;
	for (int i = 0; i < length; ++i) {
		int index = i;
		for (int j = i + 1; j < length; ++j) {
			if (vec[index] > vec[j])
				index = j;
		}
		if (index != i) {
			mySwap(vec, index, i);
		}
	}
}

int qSortArrange(vector<datatype>& vec, int low, int high) {//快排
	if (low >= high)
		return low;
	int label = vec[low];
	while (low < high) {
		while (low<high && vec[high] > label)
			--high;
		mySwap(vec, low, high);
		while (low < high && vec[low] < label)
			++low;
		mySwap(vec, low, high);
	}
	return low;
}

void qSort(vector<datatype>& vec,int low,int high) {
	if (vec.size() <= 1)
		return;
	if (low >= high)
		return;
	int mid = qSortArrange(vec, low, high);
	qSort(vec, low, mid-1);
	qSort(vec, mid + 1, high);

}

void myMergeSort(vector<datatype>& vec, int low, int mid, int high) {//归并排序
	vector<datatype> res;
	int left = low;
	int right = mid;
	while (left < mid && right <high)
	{
		if (vec[left] < vec[right]) {
			res.push_back(vec[left]);
			++left;
		}
		else {
			res.push_back(vec[right]);
			++right;
		}
	}
	while (left < mid) {
		res.push_back(vec[left++]);
	}
	while (right < high) {
		res.push_back(vec[right++]);
	}
	for (int i = 0; i < res.size(); ++i)
		vec[low++] = res[i];
}

void myMerge(vector<datatype> &vec, int low, int high) {
	if (high - low < 2)
		return;
	int mid = (low + high) >> 1;
	myMerge(vec,low, mid);
	myMerge(vec, mid, high);
	myMergeSort(vec, low, mid, high);
}

void myInsertArrange(vector<datatype>& vec) {//直接插入排序
	int length = vec.size();
	if (length <= 1)
		return;
	for (int i = 0; i < length - 1; ++i) {
		int tmpMem;
		if (vec[i] <= vec[i + 1])
			continue;
		tmpMem = vec[i + 1];
		int index = i;
		while (index >= 0 && vec[index] > tmpMem  )
		{
			vec[index + 1] = vec[index];
			--index;
		}
		vec[index + 1] = tmpMem;
	}
}

void shellArrange(vector<datatype>& vec,int increment = 1) {//希尔排序！！increment是增量，默认增量为1，即默认情况下为直接插入排序
	int length = vec.size();
	if (length <= 1)
		return;
	if (increment > length - 1) {
		cout << "增量太大！" << endl;
		return;
	}
	while (increment)
	{
		for (int teams = 0; teams < increment; ++teams) {
			int tmpMem = 0;//起临时变量的作用
			for (int index = teams; index < length - increment; index = index + increment) {
				if (vec[index] < vec[index + increment])
					continue;
				tmpMem = vec[index + increment];
				while (index > -1 && vec[index] > tmpMem) {
					vec[index + increment] = vec[index];
					index -= increment;
				}
				vec[index + increment] = tmpMem;
			}
		}
		increment = increment / 2;
	}
}

void heapArrangeSort(vector<datatype>&vec, int last_index) {
	int start_index = (last_index+1) / 2 - 1;//起始的下标
	for (int i = start_index; i >= 0; --i) {
		int left_child = i * 2 + 1;//左子节点
		if (left_child != last_index && vec[left_child] < vec[left_child + 1])//left_child != last_index得判断有无右子节点
			++left_child;
		if (vec[i] < vec[left_child])
			mySwap(vec, i, left_child);
	}
}

void heapArrange(vector<datatype>& vec) {
	int length = vec.size();
	if (length <= 1)
		return;
	for (int i = length - 1; i >= 0; --i) {
		heapArrangeSort(vec, i);//构建一个大顶堆

		mySwap(vec, i, 0);//交换堆顶元素和表尾元素，然后循环重建大顶堆！
	}
}

//int main() {
//	vector<datatype> vec = { 4,76,1,64,2,0,45 };
//	//bubbleArrange(vec);
//	//selectArrange(vec);
//	//qSort(vec, 0, 6);
//	//myMerge(vec, 0, 7);
//	//myInsertArrange(vec);
//	//shellArrange(vec,2);
//	heapArrange(vec);
//	return 0;
//}