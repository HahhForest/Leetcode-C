/* ��ָ Offer 47. ���������ֵ
��һ�� m*n �����̵�ÿһ�񶼷���һ�����ÿ�����ﶼ��һ���ļ�ֵ����ֵ���� 0��
����Դ����̵����Ͻǿ�ʼ�ø�����������ÿ�����һ��������ƶ�һ��ֱ���������̵����½�
����һ�����̼������������ļ�ֵ���������������õ����ټ�ֵ�����*/
# include<iostream>
# include<vector>
using namespace std;

/* ���䶯̬�滮
	״̬ת�ƣ�dp[i, j] = max(dp[i-1, j], dp[i, j-1]) + value[i, j]
	�߽�������dp[0, j] = �ص�0���ۼӵ�value[0, j]; dp[i, 0] = �ص�0���ۼӵ�value[i, 0]*/
class Solution {
private:
	int maxCmp(int a, int b) {
		return a > b ? a : b;
	}

public:
	int maxValue(vector<vector<int>>& grid){
		int m = grid.size();	if (m == 0)	return 0;
		int n = grid[0].size();	if (n == 0)	return 0;

		// ��ʼ��
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