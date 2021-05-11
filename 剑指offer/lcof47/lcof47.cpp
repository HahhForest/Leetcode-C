/* 剑指 Offer 47. 礼物的最大价值
在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）
你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角
给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？*/
# include<iostream>
# include<vector>
using namespace std;

/* 经典动态规划
	状态转移：dp[i, j] = max(dp[i-1, j], dp[i, j-1]) + value[i, j]
	边界条件：dp[0, j] = 沿第0行累加到value[0, j]; dp[i, 0] = 沿第0列累加到value[i, 0]*/
class Solution {
private:
	int maxCmp(int a, int b) {
		return a > b ? a : b;
	}

public:
	int maxValue(vector<vector<int>>& grid){
		int m = grid.size();	if (m == 0)	return 0;
		int n = grid[0].size();	if (n == 0)	return 0;

		// 初始化
		vector<vector<int>> dp(m, vector<int>(n, 0));
		dp[0][0] = grid[0][0];
		for (int i = 1; i < n; i++)	dp[0][i] = dp[0][i - 1] + grid[0][i];
		for (int i = 1; i < m; i++)	dp[i][0] = dp[i - 1][0] + grid[i][0];

		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				dp[i][j] = maxCmp(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
			}
		}
		return dp[m - 1][n - 1];
	}
};

int main() {
	cout << "Hello world!" << endl;
	Solution test;
}