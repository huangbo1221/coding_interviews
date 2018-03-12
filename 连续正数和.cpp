#include<iostream>
using namespace std;
/***********************
剑指offer的面试题41
************************/

void findSequence(int sum) {
	if (sum < 3)
		return;
	int small = 1, big = 2;
	while(true)
	{
		if ((big - small) == 1 && (small + big) > sum)
			break;
		int tmp = 0;
		for (int i = small; i <= big; ++i)
			tmp += i;
		if (tmp > sum)
			++small;
		else if (tmp < sum)
			++big;
		else {
			cout << sum << " = ";
			for (int j = small; j < big; ++j)
				cout << j << " + ";
			cout << big << endl;
			++big;
			++small;
		}
	}
}
//int main()
//{
//	findSequence(15);
//	return 0;
//}