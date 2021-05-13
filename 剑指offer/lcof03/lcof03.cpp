/* 剑指 Offer 03. 数组中重复的数字
找出数组中重复的数字
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次
请找出数组中任意一个重复的数字。*/
# include<iostream>
# include<vector>
using namespace std;

/* 注意此题的特殊条件：在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内
	因此若无重复，元素值可以和下标值刚好相等一一对应
	所以执行交换，在nums[i] != i时，执行nums[nums[i]]与nums[i]交换
	若发现nums[i] != i 但是 nums[nums[i]] == nums[i]，即nums[i]不在对应的位置上，但对应位置上已经有正确的值，则判定出现重复
	*/
class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		// 从头到尾，把每一位都放好
		for (int i = 0; i < nums.size(); i++) {
			while (nums[i] != i) {	// nums[i]的位置不对
				if (nums[nums[i]] == nums[i])	// 应该去的位置已经有正确的值了
					return nums[i];
				// 交换
				int tmp = nums[i]; nums[i] = nums[nums[i]]; nums[tmp] = tmp;
			}
		}

		return -1;
	}
};

int main() {
	cout << "Hello world!" << endl;
}