/******************************************
�ο���https://www.cnblogs.com/pmars/archive/2013/12/04/3458289.html
��εõ�346987521����һ��
1����β����ǰ�ҵ�һ��P(i-1) < P(i)��λ��
3 4 6 <- 9 <- 8 <- 7 <- 5 <- 2 <- 1
�����ҵ�6�ǵ�һ����С�����֣���¼��6��λ��i-1
2����iλ�������ҵ����һ������6����
3 4 6 -> 9 -> 8 -> 7 5 2 1
�����ҵ�7��λ�ã���¼λ��Ϊm
3������λ��i-1��m��ֵ
3 4 7 9 8 6 5 2 1
4������iλ�ú����������
3 4 7 1 2 5 6 8 9
��347125689Ϊ346987521����һ������
******************************************/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void mySwap(string &str, int index1, int index2) {
	char tmp = str[index1];
	str[index1] = str[index2];
	str[index2] = tmp;
}

vector<string> findAllArrange(string &str) {
	int length = str.size();//�ַ����ĳ���
	vector<string> res;//����ȫ���еĽ������
	sort(str.begin(), str.end());//���ַ���������
	res.push_back(str);//�ȱ����ʼ������
	int index = length - 1;
	int j;//��������P(i-1)���±�
	while(index > 0) {
		if (str[index] > str[index - 1])
		{
			j = index - 1;
			if (index < length - 1) {
				index = length - 1;//�Ӻ���ǰ�����ҵ���һ����str[j]�����
				while (index > j) {
					if (str[index] > str[j])
						break;
					--index;
				}
			}
			mySwap(str, j, index);//����Ԫ��
			reverse(str.begin() + j + 1, str.end());//��תj�����Ԫ�أ��õ����ַ���������һ�����У�
			res.push_back(str);
			index = length - 1;
		}
		else
		{
			index--;
		}

	}
	return res;
}

//int main() {
//	string s = "123";
//	vector<string> res;
//	res = findAllArrange(s);
//	for (int i = 0; i < res.size(); ++i)
//		cout << res[i] << endl;
//	return 0;
//}