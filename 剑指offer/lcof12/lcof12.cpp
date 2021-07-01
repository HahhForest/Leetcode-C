/* 剑指 Offer 12. 矩阵中的路径
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。*/
# include<iostream>
# include<vector>
using namespace std;

/* 回溯法，带标记的递归
	关键思想为尝试，并在尝试后还原尝试过程中的修改*/
class Solution {
private:
	// 占位标记
	char occupied = '\0';
	// 内层调用dfs，调用表示尝试
	// 由于题目要求不得重复走，因此使用回溯法，尝试当前位置可行后要做标记，在尝试后恢复，使后面的尝试可以访问
	bool dfs(vector<vector<char>>& board, string word, int m, int n, int p) {
		// 退出条件
		if (m < 0 || m >= board.size() || n < 0 || n >= board[0].size())	return false;
		// 可走但字母不对
		if (word.at(p) != board[m][n])	return false;
		// 字母对且走完
		if (p == word.size() - 1)	return true;
		// 字母对但还未走完：从当前位置继续尝试，记得使用回溯法
		// 修改当前位置为已经走过
		char tmp = board[m][n];
		board[m][n] = occupied;
		// 递归
		bool nextRes = dfs(board, word, m - 1, n, p + 1) ||
			dfs(board, word, m + 1, n, p + 1) ||
			dfs(board, word, m, n - 1, p + 1) ||
			dfs(board, word, m, n + 1, p + 1);
		// 尝试过后恢复，使后面的尝试可以走
		board[m][n] = tmp;
		
		return nextRes;
	}
public:
	// 外层函数，在地图中遍历起点
	bool exist(vector<vector<char>>& board, string word) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if (dfs(board, word, i, j, 0))	return true;
			}
		}
		return false;
	}
};

int main() {
	cout << "Hello world" << endl;

	Solution solution;
	vector<char> row1 = { 'A', 'B', 'C', 'E' };
	vector<char> row2 = { 'S', 'F', 'C', 'S' };
	vector<char> row3 = { 'A', 'D', 'E', 'E' };
	vector<vector<char>> board = { row1, row2, row3 };
	string word = "ABCCED";

	bool result = solution.exist(board, word);
	cout << result << endl;

	return 0;
}