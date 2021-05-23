/* ��ָ Offer 10- II. ������̨������
һֻ����һ�ο�������1��̨�ף�Ҳ��������2��̨�ס������������һ�� n ����̨���ܹ��ж�����������
����Ҫȡģ 1e9+7��1000000007����������ʼ���Ϊ��1000000008���뷵�� 1*/
# include<iostream>
# include<vector>
using namespace std;

/* ��̬�滮
	��dp[n]Ϊ���ϵ�n��̨�׵����������������һ��������һ����Ҳ����������
	����״̬ת�ƣ�dp[n] = dp[n-1] + dp[n-2]
	�߽�������dp[1] = 1��dp[2] = 2����˶���dp[0]Ϊ1*/
class Solution {
public:
	int numWays(int n) {
		if (n == 0)	return 1;
		if (n == 1)	return 1;

		int prepre = 1, pre = 1, now = 2;
		for (int i = 2; i <= n; i++) {
			now = (prepre + pre) % 1000000007;
			prepre = pre;
			pre = now;
		}
		return now;
	}
};

int main() {
	cout << "Hello world" << endl;
}