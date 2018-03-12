#include<iostream>
#include<vector>
using namespace std;
/////��չ��pushV�ܹ��ж����ֳ�ջ˳��http://blog.csdn.net/me4weizhen/article/details/52614298
bool IsPopOrder(vector<int> pushV, vector<int> popV) {//�ж�popV�Ƿ���pushV��һ�ֳ�ջ˳��
	if (pushV.size() == 0 || popV.size() == 0 || pushV.size() != popV.size())
		return false;
	vector<int> tmp;
	int length = pushV.size();
	for (int i = 0,j = 0; i < length;) {
		tmp.push_back(pushV[i++]);
		while (j < popV.size() && tmp.back() == popV[j])
		{
			tmp.pop_back();
			j++;
		}
	}
	return tmp.empty();
}

//int main()
//{
//	int x;
//	int i = 0;
//	while (cin >> x)
//		i++;
//	/*vector<int> vec1 = { 1,2,3,4 ,5};
//	vector<int> vec2 = { 5,4,3,2 ,2 };
//	bool flag = IsPopOrder(vec1, vec2);*/
//	return 0;
//
//}