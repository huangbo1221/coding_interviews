/**************************
剑指offer的面试题36
思路：归并排序+加逆序对统计
**************************/

#include<iostream>
#include<vector>
using namespace std;
int nums = 0;//全局变量，保存逆序数
void mergeSort(vector<int> &vec, int low, int mid, int high) {
	vector<int> res;
	int left_num = mid - low;
	int right_num = high - mid;
	int mid_index = mid-1, high_index = high-1;
	while (left_num && right_num)
	{
		if (vec[mid_index] > vec[high_index]) {
			res.push_back(vec[mid_index]);
			nums += right_num;
			--left_num;
			--mid_index;
		}
		else {
			res.push_back(vec[high_index]);
			--right_num;
			--high_index;
		}
	}
	while (mid_index > low-1)
	{
		res.push_back(vec[mid_index--]);
	}
	while (high_index > mid-1)
	{
		res.push_back(vec[high_index--]);
	}
	reverse(res.begin(), res.end());
	for (int i = 0; i < res.size(); ++i)
		vec[low++] = res[i];
}
void Merge(vector<int> &vec,int low,int high) {
	if (high - low < 2)
		return;
	int mid = (low + high) >> 1;
	Merge(vec,low, mid);
	Merge(vec,mid, high);
	mergeSort(vec, low, mid, high);
}

//int main() {
//	vector<int> vec = { 7,5,6,4 };
//	Merge(vec, 0, 4);
//	return 0;
//}