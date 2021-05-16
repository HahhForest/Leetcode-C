/* 剑指 Offer 05. 替换空格
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。*/
# include<iostream>
# include<string>
using namespace std;

/* 方法一，直观，遍历*/
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

/* 方法二，C++中string为可变类型，因此先统计空格数量，再扩展长度，然后用双指针进行搬运
	令q指向尾部，p在q前2*空格数量的位置。向前遍历，若p不为空格，则搬运；若p为空格，则q向前2步并加入空格*/
class Solution2 {
public:
	string replaceSpace(string s) {
		// 统计空格数量
		int totalSpace = 0;
		int oriLen = s.length();
		for (int i = 0; i < oriLen; i++) {
			if (s[i] == ' ') {
				totalSpace++;
			}
		}

		// 扩展string
		s.resize(s.length() + 2 * totalSpace);
		// 倒序遍历
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