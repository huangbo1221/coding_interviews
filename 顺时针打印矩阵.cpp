#include<iostream>
#include<vector>
using namespace std;

#define datatype int

vector<datatype> printArray(vector<vector<datatype>> &vec) {
	vector<datatype> res;
	if (vec.size() == 0)
		return res;
	int rows = vec.size();
	int cols = vec[0].size();
	int circle = ((rows < cols ? rows : cols)-1)/2+1;
	for (int i = 0; i < circle; ++i) {
		for (int c = i; c < cols - i; ++c)//�����Ҵ�ӡ
			res.push_back(vec[i][c]);
		for (int l = i + 1; l < rows - i; ++l)//���ϵ��´�ӡ
			res.push_back(vec[l][cols - i - 1]);
		for (int m = cols - i - 2; (m >= i) && (rows - i - 1 > i); --m)//���������ӡ,Ҫ��ֹ�ظ���ӡ
			res.push_back(vec[rows - i - 1][m]);
		for (int n = rows - i - 2; (n > i) && (cols - i - 1) != i; --n)//�������ϴ�ӡ,Ҫ��ֹ�ظ���ӡ
			res.push_back(vec[n][i]);
	}
	return res;
}

int main()
{
	vector<vector<datatype>> vec = { {1,2,3,4 },{ 5,6,7,8 } };
	printArray(vec);
	return 0;
}