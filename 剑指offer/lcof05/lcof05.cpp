/* ��ָ Offer 05. �滻�ո�
��ʵ��һ�����������ַ��� s �е�ÿ���ո��滻��"%20"��*/
# include<iostream>
# include<string>
using namespace std;

/* ����һ��ֱ�ۣ�����*/
class Solution {
public:
	string replaceSpace(string s) {
		string ans = "";
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ')	ans += "%20";
			else ans += s[i];
		}
		return ans;
	}
};

/* ��������C++��stringΪ�ɱ����ͣ������ͳ�ƿո�����������չ���ȣ�Ȼ����˫ָ����а���
	��qָ��β����p��qǰ2*�ո�������λ�á���ǰ��������p��Ϊ�ո�����ˣ���pΪ�ո���q��ǰ2��������ո�*/
class Solution2 {
public:
	string replaceSpace(string s) {
		// ͳ�ƿո�����
		int totalSpace = 0;
		int oriLen = s.length();
		for (int i = 0; i < oriLen; i++) {
			if (s[i] == ' ') {
				totalSpace++;
			}
		}

		// ��չstring
		s.resize(s.length() + 2 * totalSpace);
		// �������
		for (int p = oriLen - 1, q = s.length() - 1; p != q; p--, q--) {
			if (s[p] != ' ') {
				s[q] = s[p];
			}
			else {
				s[q--] = '0';	s[q--] = '2'; s[q] = '%';
			}
		}

		return s;
	}
};