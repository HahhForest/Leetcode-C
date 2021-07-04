/* 剑指 Offer 14- II. 剪绳子 II
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m - 1] 。请问 k[0]*k[1]*...*k[m - 1] 可能的最大乘积是多少？
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1*/
# include<iostream>
# include<vector>
using namespace std;

/* 可以和14-1相同思路，使用位数更多的整型数存储并取余即可
	
	贪心，数学推导出贪心模板。加上快速幂取余算法，不用更多位数存储也可以快速求余
	模板：尽可能以长度3分成多段（证明：均值不等式证明以相同长度分，求导并验证以长度3划分）
	
	大数越界： 当 a 增大时，最后返回的 3^a大小以指数级别增长，可能超出 int32 甚至 int64 的取值范围，导致返回值错误。
    大数求余问题： 在仅使用 int32 类型存储的前提下，正确计算x^a对p求余的值
	
	基于性质：(xy) mod p = [(x mod p) * (y mod p)] mod p
	因此：x^a mod p = (x ^ 2)^(a / 2) mod p = (x ^ 2 mod p)^(a / 2) mod p
	而a为奇数时：x^a mod p = [(x mod p) * (x^(a-1) mod p)] mod p = (x ^ 2)^(a / 2) mod p = [x * (x ^ 2 mod p)^(a // 2)] mod p*/
class Solution {
private:
	// 求x ^ a % p。p为1000000007
	long remainder(long x, int a, int p) {
		long rem = 1;
		while (a > 0) {
			if (a % 2 == 1)	rem = (rem * x) % p;
			x = (x * x) % p;
			a = a / 2;
		}

		return rem;
	}
public:
	int cuttingRope(int n) {
		if (n <= 3)	return n - 1;
		// b用来指示最后一项怎么处理。若余数为1，则要把最后一项3加进去拆成2+2；若余数为2，直接乘
		// 即先去掉一个3，若余数为0，乘上3；余数为1，乘上4，余数为2，乘上6
		int b = n % 3;

		int p = 1000000007;
		long x = 3;
		long rem = remainder(x, n / 3 - 1, p);

		switch (b) {
		case 0:
			return int((rem * 3) % p);
			break;
		case 1:
			return int((rem * 4) % p);
			break;
		default:
			return int((rem * 6) % p);
		}
	}
};

int main() {
	cout << "Hello world" << endl;
	return 0;
}