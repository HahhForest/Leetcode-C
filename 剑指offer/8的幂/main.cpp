#include <iostream>
#include <cstdio>
using namespace std;

// �����Ƿ�Ϊ8���ݣ��Ƿ���Y�����Ƿ���N
// λ���㣺һ��1���������ı�����0
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