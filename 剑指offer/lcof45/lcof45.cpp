/* ��ָ Offer 45. �������ų���С����
����һ���Ǹ��������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����*/
# include<iostream>
# include <vector>
# include <string>
using namespace std;

/* ����Ϊһ����������
	�㷨����a��bΪ���֣�����ƴ������� ab < ba������С�����У�aӦ����bǰ��
	���㷨��֤����ȷ�Ժʹ����ԣ���https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/solution/mian-shi-ti-45-ba-shu-zu-pai-cheng-zui-xiao-de-s-4/
	ʹ�ô˹�����п������򼴿�*/
class Solution {
private:
	// ����Java��String.compareTo()���ֵ�˳��Ƚϣ���a<b�򷵻�ֵС��0����֮��Ȼ
	int cmp(string a, string b) {
		int i = 0;
		int len = (a.size() > b.size()) ? b.size() : a.size();
		while (a[i] == b[i] && i < len)	i++;
		if (i == len)	
			return a.size() - b.size();
		else 
			return int(a[i]) - int(b[i]);
	}

	// �������򻮷ֺ���
	void quickSort(vector<string>& strs, int left, int right) {
		if (left >= right)	return;

		string tmp = strs[left];
		cout << tmp << endl;
		int p = left, q = right;
		while (p < q) {
			while (cmp(strs[q] + tmp, tmp + strs[q]) >= 0 && p < q)	
				q--;
			while (cmp(strs[p] + tmp, tmp + strs[p]) <= 0 && p < q)	
				p++;
			string tmpStr = strs[p]; strs[p] = strs[q]; strs[q] = tmpStr;
		}
		// ���ֿ��������Ҫ����һ��
		string tmpStr = strs[left]; strs[left] = strs[p]; strs[p] = tmpStr;
		// ����
		quickSort(strs, left, p - 1);
		quickSort(strs, p + 1, right);
	}

public:
	string minNumber(vector<int>& nums) {
		// תΪ�ַ������飬���п���ƴ�ӱȽ�
		vector<string> numStrs;
		for (int i = 0; i < nums.size(); i++) {
			numStrs.push_back(to_string(nums[i]));	// std::to_string()
		}
		// ��������
		quickSort(numStrs, 0, numStrs.size() - 1);
		// ƴ��
		string res;
		for (string s : numStrs) {
			res.append(s);
		}
		return res;
	}
};

int main() {
	cout << "Hello world!" << endl;
	vector<int> data = {0,9,8,7,6,5,4,3,2,1};
	Solution assebler;
	string ans = assebler.minNumber(data);
	cout << ans << endl;
}


