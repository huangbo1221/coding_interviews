#include<iostream>
#include<string>
using namespace std;
/*
假定一种编码的编码范围是a ~ y的25个字母，从1位到4位的编码，如果我们把该编码按字典序排序，
形成一个数组如下： a, aa, aaa, aaaa, aaab, aaac, … …, b, ba, baa, baaa, baab, baac … …, yyyw, yyyx, yyyy 其中a
的Index为0，aa的Index为1，aaa的Index为2，以此类推。 编写一个函数，输入是任意一个编码，输出这个编码对应的Index.
输入描述:
输入一个待编码的字符串,字符串长度小于等于100.


输出描述:
输出这个编码的index

输入例子1:
baca

输出例子1:
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

char* decode(int index)//根据index求出字串
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