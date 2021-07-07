/* 剑指 Offer 16. 数值的整数次方
实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，x^n）。不得使用库函数，同时不需要考虑大数问题*/
# include<iostream>
# include<vector>
using namespace std;

/* 快速幂算法
	将n写作二进制，表示为2的次幂的和，那么x^n即可表示为x的2的次幂次方的乘积
	例如n=11=1011b，则x^n=x^(1*2^0) * x^(1*2^1) * x^(0*2^2) * x^(1*2^3)
	算法：n逐次向右移位，x逐次自方。若最右边位为1，则结果乘上当前的x。若n小于0，则将x取倒数后n取反计算
	注意int的范围为 -2^31~2^31 - 1 ，因此要避免最小的负数取反后溢出
	本质上是二分思想的运用，指数向右移位的过程就是底数自方的过程，即复杂度为logn*/
class Solution {
public:
	double myPow(double x, int n) {
		// 特殊情况
		if (x == 0) return 0;
		if (x == 1) return 1;

		// 使用long存储指数，避免取反后溢出
		long b = n;
		if (b < 0) {
			x = 1 / x;
			b = -b;
		}

		// 开始向上卷
		double result = 1.0;
		while (b != 0) {
			if ((b & 1) == 1)
				result *= x;
			// 指数右移，底数自方
			b >>= 1;
			x *= x;
		}

		return result;
	}
};

int main() {
	cout << "Hello world" << endl;
	using namespace std;
}