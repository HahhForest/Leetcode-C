/* ��ָ Offer 10- I. 쳲���������
дһ������������ n ����쳲�������Fibonacci�����еĵ� n ��� F(N)��
����Ҫȡģ 1e9+7��1000000007����������ʼ���Ϊ��1000000008���뷵�� 1
쳲���������Ϊ0��1��1��2��3��5������*/
# include<iostream>
using namespace std;

/* ���Ƽ��ɣ�Ҳ���Կ����Ƕ���*/
class Solution {
public:
	int fib(int n) {
		if (n == 0)	return 0;
		if (n == 1)	return 1;

		int prepre = 0, pre = 1, now = 1;
		for (int i = 2; i <= n; i++) {
			now = (pre + prepre) % 1000000007;
			prepre = pre;
			pre = now;
		}
		return now;
	}
};

int main() {
	cout << "Hello world" << endl;
	Solution test;
	cout << test.fib(5) << endl;
}