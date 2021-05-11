/* 剑指 Offer 45. 把数组排成最小的数
输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。*/
# include<iostream>
# include <vector>
# include <string>
using namespace std;

/* 本质为一个排序问题
	算法：设a、b为数字，则若拼接运算后 ab < ba，则最小数字中，a应排在b前面
	此算法需证明正确性和传递性，见https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/solution/mian-shi-ti-45-ba-shu-zu-pai-cheng-zui-xiao-de-s-4/
	使用此规则进行快速排序即可*/
class Solution {
private:
	// 类似Java的String.compareTo()，字典顺序比较，若a<b则返回值小于0，反之亦然
	int cmp(string a, string b) {
		int i = 0;
		int len = (a.size() > b.size()) ? b.size() : a.size();
		while (a[i] == b[i] && i < len)	i++;
		if (i == len)	
			return a.size() - b.size();
		else 
			return int(a[i]) - int(b[i]);
	}

	// 快速排序划分函数
	void quickSort(vector<string>& strs, int left, int right) {
		if (left >= right)	return;

		string tmp = strs[left];
		cout << tmp << endl;
		int p = left, q = right;
		while (p < q) {
			while (cmp(strs[q] + tmp, tmp + strs[q]) >= 0 && p < q)	
				q--;
			while (cmp(strs[p] + tmp, tmp + strs[p]) <= 0 && p < q)	
				p++;
			string tmpStr = strs[p]; strs[p] = strs[q]; strs[q] = tmpStr;
		}
		// 这种快排最后需要交换一次
		string tmpStr = strs[left]; strs[left] = strs[p]; strs[p] = tmpStr;
		// 分治
		quickSort(strs, left, p - 1);
		quickSort(strs, p + 1, right);
	}

public:
	string minNumber(vector<int>& nums) {
		// 转为字符串数组，进行快速拼接比较
		vector<string> numStrs;
		for (int i = 0; i < nums.size(); i++) {
			numStrs.push_back(to_string(nums[i]));	// std::to_string()
		}
		// 快速排序
		quickSort(numStrs, 0, numStrs.size() - 1);
		// 拼接
		string res;
		for (string s : numStrs) {
			res.append(s);
		}
		return res;
	}
};

int main() {
	cout << "Hello world!" << endl;
	vector<int> data = {0,9,8,7,6,5,4,3,2,1};
	Solution assebler;
	string ans = assebler.minNumber(data);
	cout << ans << endl;
}


