/****************
��ָoffer������40
*****************/
#include<iostream>
using namespace std;

unsigned int findOneIndex(int num) {//�ҵ�num�Ķ��������е�һ��Ϊ1��index������������
	unsigned int index = 0;
	while ((num & 1) == 0 && index < 8 * sizeof(int))
	{
		num = num >> 1;
		++index;
	}
	return index;
}

bool isBit1(int num, unsigned int index) {//�ж�num�Ķ������У�indexΪ�Ķ������Ƿ�Ϊ1��������������
	return (num >> index) & 1;
}

void findOneNum(int *array, int length, int *data1, int *data2) {
	if (!array || length < 2)
		return;
	int andNum = 0;
	for (int i = 0; i < length; ++i)
		andNum ^= array[i];
	unsigned int index = findOneIndex(andNum);
	*data1 = 0;
	*data2 = 0;
	for (int i = 0; i < length; ++i) {
		if (isBit1(array[i], index))
			*data1 ^= array[i];
		else
			*data2 ^= array[i];
	}
}


//int main() {
//	int array[8] = { 2,4,3,6,3,2,5,5 };
//	int *p1 = new int(1);
//	int *p2 = new int(1);
//	findOneNum(array, 8, p1, p2);
//	delete(p1);
//	delete(p2);
//	return 0;
//}