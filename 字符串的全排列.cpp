/******************************************
参考：https://www.cnblogs.com/pmars/archive/2013/12/04/3458289.html
如何得到346987521的下一个
1，从尾部往前找第一个P(i-1) < P(i)的位置
3 4 6 <- 9 <- 8 <- 7 <- 5 <- 2 <- 1
最终找到6是第一个变小的数字，记录下6的位置i-1
2，从i位置往后找到最后一个大于6的数
3 4 6 -> 9 -> 8 -> 7 5 2 1
最终找到7的位置，记录位置为m
3，交换位置i-1和m的值
3 4 7 9 8 6 5 2 1
4，倒序i位置后的所有数据
3 4 7 1 2 5 6 8 9
则347125689为346987521的下一个排列
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
	int length = str.size();//字符串的长度
	vector<string> res;//保存全排列的结果容器
	sort(str.begin(), str.end());//按字符升序排列
	res.push_back(str);//先保存最开始的排列
	int index = length - 1;
	int j;//用来保存P(i-1)的下标
	while(index > 0) {
		if (str[index] > str[index - 1])
		{
			j = index - 1;
			if (index < length - 1) {
				index = length - 1;//从后往前数，找到第一个比str[j]大的数
				while (index > j) {
					if (str[index] > str[j])
						break;
					--index;
				}
			}
			mySwap(str, j, index);//交换元素
			reverse(str.begin() + j + 1, str.end());//反转j后面的元素，得到的字符串就是下一个排列！
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