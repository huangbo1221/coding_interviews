/**********************************
˼·�����Կ��ǴӾ�������½ǿ�ʼ����
�����½ǵ���С�ڴ����ҵ���ʱ���е���
��+1�������½ǵ������ڴ����ҵ���ʱ��
�е��±�-1
1  2  3  4
5  6  7  8
9 10 11 12
�������������������6����Ϊ9 > 6,����
�������Ա�5��6����Ϊ5<6,���ԶԱ�6��6
***********************************/
#include<iostream>
#include<vector>
using namespace std;

#define datatype int

bool findNumber(vector<vector<datatype>> &vec,datatype number) {
	if (vec.size() == 0)
		return false;
	int rows = vec.size();
	int cols = vec[0].size();
	int row_index = vec.size() - 1;//�����½ǿ�ʼ����
	int col_index = 0;
	while (row_index >= 0 && row_index < rows && col_index >= 0 && col_index < cols) {
		if (vec[row_index][col_index] < number)
			++col_index;
		else if (vec[row_index][col_index] > number)
			--row_index;
		else
			return true;
	}
	return false;
}

//int main() {
//	vector<vector<datatype>> vec = { {1,2,3,4} ,{4,5,6,7} };
//	bool res = findNumber(vec, 8);
//	return 0;
//}