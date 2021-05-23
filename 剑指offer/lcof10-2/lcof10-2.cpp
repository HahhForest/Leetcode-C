/* 剑指 Offer 10- II. 青蛙跳台阶问题
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1*/
# include<iostream>
# include<vector>
using namespace std;

/* 动态规划
	设dp[n]为跳上第n级台阶的跳法个数，则最后一步可以跳一级，也可以跳两级
	所以状态转移：dp[n] = dp[n-1] + dp[n-2]
	边界条件：dp[1] = 1，dp[2] = 2，因此定义dp[0]为1*/
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