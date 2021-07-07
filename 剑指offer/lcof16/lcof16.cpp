/* ��ָ Offer 16. ��ֵ�������η�
ʵ�� pow(x, n) �������� x �� n ���ݺ���������x^n��������ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ�������*/
# include<iostream>
# include<vector>
using namespace std;

/* �������㷨
	��nд�������ƣ���ʾΪ2�Ĵ��ݵĺͣ���ôx^n���ɱ�ʾΪx��2�Ĵ��ݴη��ĳ˻�
	����n=11=1011b����x^n=x^(1*2^0) * x^(1*2^1) * x^(0*2^2) * x^(1*2^3)
	�㷨��n���������λ��x����Է��������ұ�λΪ1���������ϵ�ǰ��x����nС��0����xȡ������nȡ������
	ע��int�ķ�ΧΪ -2^31~2^31 - 1 �����Ҫ������С�ĸ���ȡ�������
	�������Ƕ���˼������ã�ָ��������λ�Ĺ��̾��ǵ����Է��Ĺ��̣������Ӷ�Ϊlogn*/
class Solution {
public:
	double myPow(double x, int n) {
		// �������
		if (x == 0) return 0;
		if (x == 1) return 1;

		// ʹ��long�洢ָ��������ȡ�������
		long b = n;
		if (b < 0) {
			x = 1 / x;
			b = -b;
		}

		// ��ʼ���Ͼ�
		double result = 1.0;
		while (b != 0) {
			if ((b & 1) == 1)
				result *= x;
			// ָ�����ƣ������Է�
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