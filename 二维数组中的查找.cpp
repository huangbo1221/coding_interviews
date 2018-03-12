/**********************************
思路：可以考虑从矩阵的左下角开始查找
当左下角的数小于待查找的数时，列的下
标+1，当左下角的数大于待查找的数时，
行的下标-1
1  2  3  4
5  6  7  8
9 10 11 12
比如在上述矩阵里查找6，因为9 > 6,所以
接下来对比5和6，因为5<6,所以对比6和6
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
	int row_index = vec.size() - 1;//从左下角开始查找
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