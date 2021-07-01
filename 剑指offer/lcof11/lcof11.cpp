/* 剑指 Offer 11. 旋转数组的最小数字
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转
输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1  */
#include <iostream>
#include <vector>
using namespace std;

/* 直接线性探测
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

// 二分法
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