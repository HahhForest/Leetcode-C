/* ��ָ Offer 11. ��ת�������С����
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת
����һ����������������һ����ת�������ת�������СԪ�ء����磬���� [3,4,5,1,2] Ϊ [1,2,3,4,5] ��һ����ת�����������СֵΪ1  */
#include <iostream>
#include <vector>
using namespace std;

/* ֱ������̽��
*/
class Solution {
public:
    int minArray(vector<int>& numbers) {
        if (numbers.size() == 0) {
            return 0;
        }

        for (int i = 1; i < numbers.size(); i++) {
            if (numbers[i] < numbers[i - 1]) {
                return numbers[i];
            }
        }
        return numbers[0];
    }
};

// ���ַ�
class Solution2 {
public:
    int minArray(vector<int>& numbers) {
        return 0;
    }
};

int main() {
	cout << "Hello world" << endl;
    vector<int> data(5);
    int lst[5] = { 3,4,5,1,2 };
    for (int i = 0; i < 5; i++) {
        data[i] = lst[i];
    }
    Solution test;
    int ans = test.minArray(data);
    cout << ans << endl;
}