/* 剑指 Offer 15. 二进制中1的个数
编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为 汉明重量).）*/
# include<iostream>
# include<vector>
using namespace std;

/* 常规解法：逐个移位并与1做与运算判断
	更好的解法：使用n & (n - 1)，每一次都消去二进制数最右边的一位1。
	(n - 1)：最右边的1变成0，1右边的所有0变成1。与运算后消去最右边的1*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
		int total = 0;
		while (n != 0) {
			n &= (n - 1);
			total++;
		}
		return total;
    }
};

int main() {
	cout << "Hello world" << endl;
	return 0;
}