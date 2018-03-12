/*******************************
剑指offer面试题33.
剑指offer针对的是正整数数组！！
扩展：若存在0？？
*******************************/

#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
using namespace std;

bool myCompare(string &s1,string &s2) {
	string tmp1 = s1 + s2;
	string tmp2 = s2 + s1;
	return tmp1 < tmp2;
}

void minimumNum(int *array, int length) {
	if (length < 1 || !array)
		return;
	int L = length;
	string *str = new string[length];
	for (int i = 0; i < length; ++i) {
		stringstream str_in;
		str_in << array[i];
		str_in >> str[i];
	}
	sort(str, str + length, myCompare);
	for (int i = 0; i < length; ++i)
		cout << str[i];
	cout << endl;
	delete []str;
}

//int main() {
//	int arr[3] = { 3,321,0 };
//	minimumNum(arr, 3);
//	return 0;
//}