/* 剑指 Offer 04. 二维数组中的查找
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序
请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。*/
# include<iostream>
# include<vector>
using namespace std;

/* 线性探测。因为两个方向都是增大，无法分情况探测。因此希望能够找一个方法向二叉搜索树一样，一边大一边小
	所以从matrix[m][0]开始，即左下角。向上减小，向右增大*/
class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		if (m == 0) return false;
		int n = matrix[0].size();

		int i = m - 1, j = 0;
		bool isFind = false;
		while (i >= 0 && j < n) {
			if (matrix[i][j] == target) {
				isFind = true;
				break;
			}
			else if (target < matrix[i][j])	i--;
			else j++;
		}

		return isFind;
	}
};

int main() {
	int data[5][5] = { {1, 4, 7, 11, 15},{2, 5, 8, 12, 19},{3, 6, 9, 16, 22},{10, 13, 14, 17, 24},{18, 21, 23, 26, 30} };
	vector<vector<int>> matrix(5, vector<int>(5));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			matrix[i][j] = data[i][j];
		}
	}

	Solution test;
	bool res = test.findNumberIn2DArray(matrix, 5);

	cout << "Hello world" << endl;
}