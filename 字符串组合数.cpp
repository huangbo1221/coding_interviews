#include<iostream>
#include<string>
using namespace std;
/*
�ٶ�һ�ֱ���ı��뷶Χ��a ~ y��25����ĸ����1λ��4λ�ı��룬������ǰѸñ��밴�ֵ�������
�γ�һ���������£� a, aa, aaa, aaaa, aaab, aaac, �� ��, b, ba, baa, baaa, baab, baac �� ��, yyyw, yyyx, yyyy ����a
��IndexΪ0��aa��IndexΪ1��aaa��IndexΪ2���Դ����ơ� ��дһ������������������һ�����룬�����������Ӧ��Index.
��������:
����һ����������ַ���,�ַ�������С�ڵ���100.


�������:
�����������index

��������1:
baca

�������1:
16331
*/

int f[] = { 1 + 25 + 25 * 25 + 25 * 25 * 25 ,1 + 25 + 25 * 25 ,1+25,1};

int calIndex(string s)
{
	int n = s.length();
	int index = 0;
	switch (n)
	{
	case 1:
		index = (s[0] - 'a')*f[3];
		break;
	case 2:
		index = (s[0] - 'a')*f[3] + (s[1] - 'a')*f[2] + 1;
		break;
	case 3:
		index = (s[0] - 'a')*f[3] + (s[1] - 'a')*f[2] + (s[2] - 'a')*f[1] + 2;
		break;
	case 4:
		index = (s[0] - 'a')*f[3] + (s[1] - 'a')*f[2] + (s[2] - 'a')*f[1] + (s[3] - 'a') + 3;
		break;
	default:
		break;
	}
	return index;
}

char* decode(int index)//����index����ִ�
{
	char str[4];
	int i = 0;
	while (index >= 0)
	{
		str[i] = 'a' + index / f[i];
		index = index % f[i];
		--index;
		++i;
	}
	str[i] = '\0';
	return str;
}

//int main()
//{
//	string s;
//	cin >> s;
//	int index = calIndex(s);
//	return 0;
//}