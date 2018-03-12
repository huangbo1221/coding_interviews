/***********************************************
给定一个正整数，编写程序计算有多少对质数的和等于
输入的这个正整数，并输出结果。输入值小于1000。
如，输入为10, 程序应该输出结果为2。（共有两对质
数的和为10,分别为(5,5),(3,7)） 
*************************************************/
#include<iostream>
#include<math.h>
using namespace std;


bool judgeSuShu(int n) {
	int end = int(sqrt(n));
	for (int i = 2; i <= end; ++i)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int judge(int num) {
	if (num == 2 || num == 3)
		return 0;
	int total = 0;
	int end = num / 2;
	int i = 2;
	for (; i <end; ++i) {
		if (judgeSuShu(i) && judgeSuShu(num - i))
			total++;
	}
	if (end == num / 2 && judgeSuShu(end))
		total++;
	return total;
}

int main()
{
	int n;
	cin >> n;
	int nums = judge(n);
	return 0;
}