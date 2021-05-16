/* 1647. 字符频次唯一的最小删除次数
如果字符串 s 中 不存在 两个不同字符 频次 相同的情况，就称 s 是 优质字符串 。

给你一个字符串 s，返回使 s 成为 优质字符串 需要删除的 最小 字符数。

字符串中字符的 频次 是该字符在字符串中的出现次数。例如，在字符串 "aab" 中，'a' 的频次是 2，而 'b' 的频次是 1 。*/
# include<iostream>
# include<set>
using namespace std;

/* 统计每个数字的出现次数，使用哈希表存储
    遍历，若此次数出现过，则将当前字母减一个
    先不考虑排序*/
class Solution {
public:
    int minDeletions(string& S) {
        int ascllOfa = 97;

        // 统计频次
        int count[26] = {0};
        for (int i = 0; i < S.size(); i++) {
            count[int(S[i]) - ascllOfa]++;
        }

        // 贪心，从头到尾遍历
        set<int> map;
        int totalDel = 0;
        for (int i = 0; i < 26; i++) {
            // 已存在且不为0，一直删除直到不存在
            while (map.count(count[i]) != 0 && count[i] != 0) {  
                count[i]--;
                totalDel++;
            }
            // 若不为0，加入集合
            if (count[i] != 0) {
                map.insert(count[i]);
            }
        }

        return totalDel;
    }
};

int main() {
    cout << "Hello world" << endl;
}