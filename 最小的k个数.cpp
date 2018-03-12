/************************
剑指offer30
最小的k个数
*************************/
#include<iostream>
using namespace std;

void swap(int *p1, int *p2) {
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int Partition(int *p, int low, int high) {
	int num = p[low];
	while (low < high) {
		while (low < high && num <= p[high])
			--high;
		swap(p[low], p[high]);
		while (low<high && num >= p[low])
			++low;
		swap(p[low], p[high]);
	}
	return low;
}

void qSort(int *p, int low,int high) {
	if (low >= high)
		return;
	int mid = Partition(p, low, high);
	qSort(p, low, mid - 1);
	qSort(p, mid + 1, high);
}

void findSmallKNum(int *p, int length, int k) {
	if (!p || k > length || length < 0 || k < 0)
		return;
	int index=0 ,low = 0, high = length - 1;
	while (index != k) {
		index = Partition(p, low, high);
		if (index  > k)
			high = index - 1;
		if (index  < k)
			high = index + 1;
		if (index == 0)
			break;
	}
	for (int i = 0; i < k; ++i)
		cout << p[i] << " ";
	cout << endl;
 }

//int main()
//{
//	int a[8] = { 56,23,8,1,9,100,3,6 };
//	findSmallKNum(a, 8, 2);
//	return 0;
//}