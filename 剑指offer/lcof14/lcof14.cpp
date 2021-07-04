/* 剑指 Offer 14- I. 剪绳子
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18*/
# include<iostream>
# include<vector>
using namespace std;

/* 动态规划，设dp[i]为长度为i的绳子剪断后的最大乘积
	绳子若剪去长度为 j 的一段，则剩下的 i - j 可以剪断（dp[i-j]）也可以不剪断。因此为max(j * (i - j), j * dp[i - j])
	这里的 j 在2到 i - 1 中取值。因此dp[i] = max_{j}(j * (i - j), j * dp[i - j])
	
	注意，dp[i]并不一定包括 i ，因为题目要求至少要剪一刀。如dp[2] = 1 * 1 = 1 < 2*/
class Solution {
private:
	int max(int x, int y) {
		return x > y ? x : y;
	}

public:
	int cuttingRope(int n) {
		// 边界条件
		vector<int> dp(n + 5, 0);
		dp[1] = 1; dp[2] = 1;
		 
		// 从下向上递推
		for (int i = 3; i <= n; i++) {
			for (int j = 2; j < i; j++) {
				dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
			}
		}

		return dp[n];
	}
};

int main() {
	cout << "Hello world" << endl;
	return 0;
}