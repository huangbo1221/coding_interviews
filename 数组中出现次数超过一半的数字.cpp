/**************************
找出数组中超过一半的数字
剑指offer面试题29
***************************/
#include<iostream>
#include<vector>
using namespace std;

#define datatype int

bool flag = false;

datatype findExceedHalfNum(vector<datatype> &vec) {
	int length = vec.size();
	if (length < 1)
	{
		flag = true;
		return -1;
	}
	int numMem = vec[0],times = 1;
	for (int i = 1; i < length; ++i) {
		if (numMem == vec[i])
			++times;
		else {
			--times;
			if (times == 0) {
				numMem = vec[i];
				times = 1;
			}
		}
	}
	int tmp = 0;
	for (int i = 0; i < length; ++i)
	{
		if (numMem == vec[i])
			++tmp;
	}
	if (tmp * 2 > length)
		return numMem;
	else
	{
		flag = true;
		return -1;
	}		
}


//int main() {
//	vector<datatype> vec = { 1,6,3,3,9,10,55,11,3,3,3,3,3,3 };
//	datatype res = findExceedHalfNum(vec);
//	if (flag)
//		cout << "no number exceed the half of the vector!" << endl;
//	else
//		cout << res << endl;
//	return 0;
//}
//
