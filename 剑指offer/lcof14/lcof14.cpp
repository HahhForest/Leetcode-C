/* ��ָ Offer 14- I. ������
����һ������Ϊ n �����ӣ�������Ӽ����������ȵ� m �Σ�m��n����������n>1����m>1����ÿ�����ӵĳ��ȼ�Ϊ k[0],k[1]...k[m-1] ������ k[0]*k[1]*...*k[m-1] ���ܵ����˻��Ƕ��٣�
���磬�����ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3�����Σ���ʱ�õ������˻���18*/
# include<iostream>
# include<vector>
using namespace std;

/* ��̬�滮����dp[i]Ϊ����Ϊi�����Ӽ��Ϻ�����˻�
	��������ȥ����Ϊ j ��һ�Σ���ʣ�µ� i - j ���Լ��ϣ�dp[i-j]��Ҳ���Բ����ϡ����Ϊmax(j * (i - j), j * dp[i - j])
	����� j ��2�� i - 1 ��ȡֵ�����dp[i] = max_{j}(j * (i - j), j * dp[i - j])
	
	ע�⣬dp[i]����һ������ i ����Ϊ��ĿҪ������Ҫ��һ������dp[2] = 1 * 1 = 1 < 2*/
class Solution {
private:
	int max(int x, int y) {
		return x > y ? x : y;
	}

public:
	int cuttingRope(int n) {
		// �߽�����
		vector<int> dp(n + 5, 0);
		dp[1] = 1; dp[2] = 1;
		 
		// �������ϵ���
		for (int i = 3; i <= n; i++) {
			for (int j = 2; j < i; j++) {
				dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
			}
		}

		return dp[n];
	}
};

int main() {
	cout << "Hello world" << endl;
	return 0;
}