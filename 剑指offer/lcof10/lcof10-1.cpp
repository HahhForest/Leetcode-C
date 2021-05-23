/* 剑指 Offer 10- I. 斐波那契数列
写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）
答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1
斐波那契数列为0，1，1，2，3，5，，，*/
# include<iostream>
using namespace std;

/* 递推即可，也可以看作是动规*/
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