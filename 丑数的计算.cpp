/*********************************************
把只包含因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含因子7。 
习惯上我们把1当做是第一个丑数。求按从小到大的
顺序的第N个丑数。

思路：剑指offer面试题34
********************************************/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findUglyNumber(int index) {//index表示第几个，从1开始。不符合条件返回-1
	if (index < 1)
		return -1;
	vector<int> vec(index);
	vec[0] = 1;
	int t2 = 0, t3 = 0, t5 = 0;
	for (int i = 1; i < index; ++i) {
		vec[i] = min(vec[t2]*2, min(vec[t3]*3,vec[t5]*5));
		if (vec[i] == vec[t2] * 2) ++t2;
		if (vec[i] == vec[t3] * 3) ++t3;
		if (vec[i] == vec[t5] * 5) ++t5;
	}
	return vec[index - 1];
}

//int main() {
//	int num = findUglyNumber(3);
//	return 0;
//}