#include <stdio.h>
#include <string.h>

#include <iostream>
using namespace std;

//****************************�ݹ飡����
//func:��ȡn������ָ�������ͳ��ֵĴ���
//para:n:���Ӹ���;sum:ָ���ĵ�����
//return:������Ϊsum��������
//****************************/
//int getNSumCount(int n, int sum) {
//	if (n<1 || sum<n || sum>6 * n) {
//		return 0;
//	}
//	if (n == 1) {
//		return  1;
//	}
//	int resCount = 0;
//	resCount = getNSumCount(n - 1, sum - 1) + getNSumCount(n - 1, sum - 2) +
//		getNSumCount(n - 1, sum - 3) + getNSumCount(n - 1, sum - 4) +
//		getNSumCount(n - 1, sum - 5) + getNSumCount(n - 1, sum - 6);
//	return resCount;
//}
//
////��֤
//int main() {
//	int n = 0;
//	while (true) {
//		cout << "input dice num��";
//		cin >> n;
//		for (int i = n; i <= 6 * n; ++i)
//			cout << "f(" << n << "," << i << ")=" << getNSumCount(n, i) << endl;
//	}
//}




/****************************************�ǵݹ飡����
func:����������Ŀn�������п��ܵ����͵�������
para��n:���Ӹ���;count:��Ÿ��ֵ����͵����������±�i��ʾ������Ϊ��i+n��
f(n,sum)=f(n-1,sum-1)+f(n-1,sum-2)+f(n-1,sum-3)+f(n-1,sum-4)+f(n-1,sum-5)+f(n-1,sum-6)
f(n,sum)����count[sum-n]��ʾ
����ʽ�ɱ�ʾΪcount[sum-n]=count[sum-1-(n-1)]+count[sum-2-(n-1)]+count[sum-3-(n-1)]+count[sum-4-(n-1)]+count[sum-5-(n-1)]+count[sum-6-(n-1)]
return:������-1���ɹ�����0
****************************************/
int getNSumCountNotRecusion(int n, int* count) {
	if (n<1)
		return -1;
	//��ʼ�����״̬
	count[0] = count[1] = count[2] = count[3] = count[4] = count[5] = 1;
	if (n == 1) return 0;

	for (int i = 2; i <= n; ++i) {
		for (int sum = 6 * i; sum >= i; --sum) {
			int tmp1 = ((sum - 1 - (i - 1)) >= 0 ? count[sum - 1 - (i - 1)] : 0); //��һ�׶ε�����sum-1����������
			int tmp2 = (sum - 2 - (i - 1) >= 0 ? count[sum - 2 - (i - 1)] : 0);
			int tmp3 = (sum - 3 - (i - 1) >= 0 ? count[sum - 3 - (i - 1)] : 0);
			int tmp4 = (sum - 4 - (i - 1) >= 0 ? count[sum - 4 - (i - 1)] : 0);
			int tmp5 = (sum - 5 - (i - 1) >= 0 ? count[sum - 5 - (i - 1)] : 0);
			int tmp6 = (sum - 6 - (i - 1) >= 0 ? count[sum - 6 - (i - 1)] : 0);
			count[sum - i] = tmp1 + tmp2 + tmp3 + tmp4 + tmp5 + tmp6;
		}
	}
	return 0;
}

//��֤
//int main() {
//	int n;
//	while (true) {
//		cout << "iteration input dice num��";
//		cin >> n;
//		int* count = new int[5 * n + 1];//n�����ӵ�ȡֵ��ΧΪn-->6n������5n+1����
//		memset(count, 0, (5 * n + 1) * sizeof(int));//��5n+1��ֵȫ����ʼ��Ϊ0
//		getNSumCountNotRecusion(n, count);
//		int allCount = 0;
//		for (int i = 0; i<5 * n + 1; ++i) {
//			cout << "f(" << n << "," << i + n << ")=" << count[i] << endl;
//			allCount += count[i];
//		}
//		delete[] count;
//	}
//}