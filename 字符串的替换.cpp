#include<iostream>
using namespace std;

void replaceStr(char * str) {
	if (!str)
		return;
	int ori_length = strlen(str)+1;
	int space_num = 0;
	for (int i = 0; i < ori_length; ++i) {
		if (str[i] == ' ')
			++space_num;
	}
	int new_length = ori_length + space_num * 2;
	int ori_index = ori_length - 1;
	int new_index = new_length - 1;
	while (new_index != ori_index) {
		if (str[ori_index] != ' ')
			str[new_index--] = str[ori_index--];
		else {
			str[new_index] = '0';
			str[new_index-1] = '2';
			str[new_index-2] = '%';
			new_index = new_index - 3;
			--ori_index;//不让ori_index再指向空格了！！！
		}
	}
}

//int main() {
//	char p[] = "we are  happy.";
//	//char *p = "we are  happy.";报错！const char * 不能到char *!!!
//	replaceStr(p);
//	cout << p << endl;
//	return 0;
//}