/* 剑指 Offer 46. 把数字翻译成字符串
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译
请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法*/
# include<iostream>
# include<string>
using namespace std;

/* 使用动态规划，根据前一状态结果推后一状态结果
	观察可以看到，对于连续的两位数字x_n-1x_n：
		若此两位数字可以被翻译（如23），则到这两位数字结束的翻译有f(n-2) + f(n-1)种
		若此两位数字不可被翻译（如53），则到这两位数字结束的翻译有f(n-1)种
	因此定义状态转移方程dp[n]：n位数的翻译方法；边界条件dp[0] = dp[1] = 1。这里定义dp[0] = 1是为了计算末两位可以翻译的dp[2]时转移方程的正确性*/
class Solution {
private:
	int str2Int(char& dec, char& unit) {
		return 10 * (int(dec) - 48) + int(unit) - 48;
	}
public:
	int translateNum(int num) {
		int prepre = 1, pre = 1;
		string numStr = to_string(num);
		//cout << numStr << endl;
		for (int i = 1; i < numStr.size(); i++) {
			// 最后两位转化为整数
			int flag = str2Int(numStr[i - 1], numStr[i]);
			//cout << flag << endl;
			// 状态转移
			int p = (flag >= 10 && flag <= 25) ? prepre + pre : pre;
			//cout << p << endl;
			// 迭代
			prepre = pre; pre = p;
		}
		return pre;
	}
};

int main() {
	cout << "Hello world!" << endl;
	Solution trans;
	cout << trans.translateNum(12258) << endl;
}

