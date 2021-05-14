/* ��ָ Offer 04. ��ά�����еĲ���
��һ�� n * m �Ķ�ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
�����һ����Ч�ĺ���������������һ����ά�����һ���������ж��������Ƿ��и�������*/
# include<iostream>
# include<vector>
using namespace std;

/* ����̽�⡣��Ϊ���������������޷������̽�⡣���ϣ���ܹ���һ�����������������һ����һ�ߴ�һ��С
	���Դ�matrix[m][0]��ʼ�������½ǡ����ϼ�С����������*/
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