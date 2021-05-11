/* ��ָ Offer 46. �����ַ�����ַ���
����һ�����֣����ǰ������¹����������Ϊ�ַ�����0 ����� ��a�� ��1 ����� ��b����������11 ����� ��l����������25 ����� ��z����һ�����ֿ����ж������
����ʵ��һ����������������һ�������ж����ֲ�ͬ�ķ��뷽��*/
# include<iostream>
# include<string>
using namespace std;

/* ʹ�ö�̬�滮������ǰһ״̬����ƺ�һ״̬���
	�۲���Կ�����������������λ����x_n-1x_n��
		������λ���ֿ��Ա����루��23����������λ���ֽ����ķ�����f(n-2) + f(n-1)��
		������λ���ֲ��ɱ����루��53����������λ���ֽ����ķ�����f(n-1)��
	��˶���״̬ת�Ʒ���dp[n]��nλ���ķ��뷽�����߽�����dp[0] = dp[1] = 1�����ﶨ��dp[0] = 1��Ϊ�˼���ĩ��λ���Է����dp[2]ʱת�Ʒ��̵���ȷ��*/
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
			// �����λת��Ϊ����
			int flag = str2Int(numStr[i - 1], numStr[i]);
			//cout << flag << endl;
			// ״̬ת��
			int p = (flag >= 10 && flag <= 25) ? prepre + pre : pre;
			//cout << p << endl;
			// ����
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

