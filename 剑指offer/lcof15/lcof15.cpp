/* ��ָ Offer 15. ��������1�ĸ���
��дһ��������������һ���޷����������Զ����ƴ�����ʽ��������������Ʊ��ʽ������λ��Ϊ '1' �ĸ�����Ҳ����Ϊ ��������).��*/
# include<iostream>
# include<vector>
using namespace std;

/* ����ⷨ�������λ����1���������ж�
	���õĽⷨ��ʹ��n & (n - 1)��ÿһ�ζ���ȥ�����������ұߵ�һλ1��
	(n - 1)�����ұߵ�1���0��1�ұߵ�����0���1�����������ȥ���ұߵ�1*/
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