/*********************************************
��ֻ��������2��3��5��������������Ugly Number����
����6��8���ǳ�������14���ǣ���Ϊ����������7�� 
ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����
˳��ĵ�N��������

˼·����ָoffer������34
********************************************/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findUglyNumber(int index) {//index��ʾ�ڼ�������1��ʼ����������������-1
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