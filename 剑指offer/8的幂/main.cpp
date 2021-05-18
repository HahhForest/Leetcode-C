#include <iostream>
#include <cstdio>
using namespace std;

// 计算是否为8的幂，是返回Y，不是返回N
// 位运算：一个1，后面三的倍数个0
char calc(int num) {
	while ((num & 7) == 0) {
		num = num >> 3;
	}
	if (num != 0x01)		return 'N';
	else return 'Y';
}

int main() {
	unsigned n, num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &num);
		printf_s("%c ", calc(num));
	}

	return 0;
}