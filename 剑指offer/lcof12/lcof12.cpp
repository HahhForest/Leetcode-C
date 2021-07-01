/* ��ָ Offer 12. �����е�·��
����һ�� m x n ��ά�ַ����� board ��һ���ַ������� word ����� word �����������У����� true �����򣬷��� false ��

���ʱ��밴����ĸ˳��ͨ�����ڵĵ�Ԫ���ڵ���ĸ���ɣ����С����ڡ���Ԫ������Щˮƽ���ڻ�ֱ���ڵĵ�Ԫ��ͬһ����Ԫ���ڵ���ĸ�������ظ�ʹ�á�*/
# include<iostream>
# include<vector>
using namespace std;

/* ���ݷ�������ǵĵݹ�
	�ؼ�˼��Ϊ���ԣ����ڳ��Ժ�ԭ���Թ����е��޸�*/
class Solution {
private:
	// ռλ���
	char occupied = '\0';
	// �ڲ����dfs�����ñ�ʾ����
	// ������ĿҪ�󲻵��ظ��ߣ����ʹ�û��ݷ������Ե�ǰλ�ÿ��к�Ҫ����ǣ��ڳ��Ժ�ָ���ʹ����ĳ��Կ��Է���
	bool dfs(vector<vector<char>>& board, string word, int m, int n, int p) {
		// �˳�����
		if (m < 0 || m >= board.size() || n < 0 || n >= board[0].size())	return false;
		// ���ߵ���ĸ����
		if (word.at(p) != board[m][n])	return false;
		// ��ĸ��������
		if (p == word.size() - 1)	return true;
		// ��ĸ�Ե���δ���꣺�ӵ�ǰλ�ü������ԣ��ǵ�ʹ�û��ݷ�
		// �޸ĵ�ǰλ��Ϊ�Ѿ��߹�
		char tmp = board[m][n];
		board[m][n] = occupied;
		// �ݹ�
		bool nextRes = dfs(board, word, m - 1, n, p + 1) ||
			dfs(board, word, m + 1, n, p + 1) ||
			dfs(board, word, m, n - 1, p + 1) ||
			dfs(board, word, m, n + 1, p + 1);
		// ���Թ���ָ���ʹ����ĳ��Կ�����
		board[m][n] = tmp;
		
		return nextRes;
	}
public:
	// ��㺯�����ڵ�ͼ�б������
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