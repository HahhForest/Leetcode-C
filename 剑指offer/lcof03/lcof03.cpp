/* ��ָ Offer 03. �������ظ�������
�ҳ��������ظ�������
��һ������Ϊ n ������ nums ����������ֶ��� 0��n-1 �ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�Ҳ��֪��ÿ�������ظ��˼���
���ҳ�����������һ���ظ������֡�*/
# include<iostream>
# include<vector>
using namespace std;

/* ע������������������һ������Ϊ n ������ nums ����������ֶ��� 0��n-1 �ķ�Χ��
	��������ظ���Ԫ��ֵ���Ժ��±�ֵ�պ����һһ��Ӧ
	����ִ�н�������nums[i] != iʱ��ִ��nums[nums[i]]��nums[i]����
	������nums[i] != i ���� nums[nums[i]] == nums[i]����nums[i]���ڶ�Ӧ��λ���ϣ�����Ӧλ�����Ѿ�����ȷ��ֵ�����ж������ظ�
	*/
class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		// ��ͷ��β����ÿһλ���ź�
		for (int i = 0; i < nums.size(); i++) {
			while (nums[i] != i) {	// nums[i]��λ�ò���
				if (nums[nums[i]] == nums[i])	// Ӧ��ȥ��λ���Ѿ�����ȷ��ֵ��
					return nums[i];
				// ����
				int tmp = nums[i]; nums[i] = nums[nums[i]]; nums[tmp] = tmp;
			}
		}

		return -1;
	}
};

int main() {
	cout << "Hello world!" << endl;
}