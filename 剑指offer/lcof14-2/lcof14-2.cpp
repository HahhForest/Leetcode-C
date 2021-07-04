/* ��ָ Offer 14- II. ������ II
����һ������Ϊ n �����ӣ�������Ӽ����������ȵ� m �Σ�m��n����������n>1����m>1����ÿ�����ӵĳ��ȼ�Ϊ k[0],k[1]...k[m - 1] ������ k[0]*k[1]*...*k[m - 1] ���ܵ����˻��Ƕ��٣�
���磬�����ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3�����Σ���ʱ�õ������˻���18��

����Ҫȡģ 1e9+7��1000000007����������ʼ���Ϊ��1000000008���뷵�� 1*/
# include<iostream>
# include<vector>
using namespace std;

/* ���Ժ�14-1��ͬ˼·��ʹ��λ��������������洢��ȡ�༴��
	
	̰�ģ���ѧ�Ƶ���̰��ģ�塣���Ͽ�����ȡ���㷨�����ø���λ���洢Ҳ���Կ�������
	ģ�壺�������Գ���3�ֳɶ�Σ�֤������ֵ����ʽ֤������ͬ���ȷ֣��󵼲���֤�Գ���3���֣�
	
	����Խ�磺 �� a ����ʱ����󷵻ص� 3^a��С��ָ���������������ܳ��� int32 ���� int64 ��ȡֵ��Χ�����·���ֵ����
    �����������⣺ �ڽ�ʹ�� int32 ���ʹ洢��ǰ���£���ȷ����x^a��p�����ֵ
	
	�������ʣ�(xy) mod p = [(x mod p) * (y mod p)] mod p
	��ˣ�x^a mod p = (x ^ 2)^(a / 2) mod p = (x ^ 2 mod p)^(a / 2) mod p
	��aΪ����ʱ��x^a mod p = [(x mod p) * (x^(a-1) mod p)] mod p = (x ^ 2)^(a / 2) mod p = [x * (x ^ 2 mod p)^(a // 2)] mod p*/
class Solution {
private:
	// ��x ^ a % p��pΪ1000000007
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
		// b����ָʾ���һ����ô����������Ϊ1����Ҫ�����һ��3�ӽ�ȥ���2+2��������Ϊ2��ֱ�ӳ�
		// ����ȥ��һ��3��������Ϊ0������3������Ϊ1������4������Ϊ2������6
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