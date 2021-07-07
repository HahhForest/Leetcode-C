/* 剑指 Offer 17. 打印从1到最大的n位数
输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999*/
# include<iostream>
# include<cmath>
# include<stack>
# include<vector>
# include<string>
using namespace std;

/* 最大的数是10^n - 1。考虑大数越界问题，使用字符串来生成数字
    基本规律：一个数的高位若比另一个数的高位小，则这个数一定比另一个数小；一个数若位数比另一个数少，则也一定比另一个数小
    使用dfs遍历所有组合，即可从小到大遍历所有数字
    外层一个循环从1到n遍历所有位数。对于每个位数，dfs其所有组合。由于首位不为0，因此对于首位的数字使用循环，第二位开始交给dfs
    使用栈做非递归的dfs*/
class Solution {
private:
    class numStruct{
    public:
        string num; // 字符串化的数
        int digit;  // 数的位数
        int index;  // 现在写了几位了（即接下来写的位数的下标）
        numStruct(string number, int dgt, int idx) {
            num = number;
            digit = dgt;
            index = idx;
        }
    };
public:
    vector<int> printNumbers(int n) {
        vector<int> res(pow(10, n) - 1);
        // 指示res填充到第几位了
        int resIdx = 0;
        // 遍历数的位数
        for (int digit = 1; digit <= n; digit++) {
            // 遍历最高位的数字
            for (char first = '1'; first <= '9'; first++) {
                // 使用dfs从小到大遍历当前位数当前开头的所有组合
                // 开始：digit位长，只要第一位是first就行，后面的可以覆写
                string beginStr(1, first);
                stack<numStruct*> s;

                // 开始dfs
                numStruct* beginStruct = new numStruct(beginStr, digit, 1);
                s.push(beginStruct);
                while (!s.empty()) {
                    numStruct* tmp = s.top();
                    s.pop();
                    // 当前数构造完毕：加入结果数组
                    if (tmp->digit == tmp->index) {
                        // cout << tmp->digit << "!!!" << tmp->index << endl;
                        // cout << atoi(tmp->num.c_str()) << endl;
                        res[resIdx++] = atoi(tmp->num.c_str());
                    }
                    // 未构造完毕：从大到小压栈
                    else {
                        for (char first = '9'; first >= '0'; first--) {
                            string toPush = tmp->num + string(1, first);
                            numStruct* pushIn = new numStruct(toPush, tmp->digit, tmp->index + 1);
                            s.push(pushIn);
                            //delete pushIn;
                        }
                    }
                    //delete tmp;
                }
                //delete beginStruct;
            }
        }
        return res;
    }
};

///* 最大的数是10^n - 1。考虑大数越界问题，使用字符串来生成数字
//    基本规律：一个数的高位若比另一个数的高位小，则这个数一定比另一个数小；一个数若位数比另一个数少，则也一定比另一个数小
//    使用dfs遍历所有组合，即可从小到大遍历所有数字
//    外层一个循环从1到n遍历所有位数。对于每个位数，dfs其所有组合。由于首位不为0，因此对于首位的数字使用循环，第二位开始交给dfs
//    使用栈做非递归的dfs*/
//class Solution {
//private:
//    class numStruct {
//    public:
//        string num; // 字符串化的数
//        int digit;  // 数的位数
//        int index;  // 现在写了几位了（即接下来写的位数的下标）
//        numStruct(string number, int idx) {
//            num = number;
//            index = idx;
//        }
//    };
//public:
//    vector<int> printNumbers(int n) {
//        vector<int> res(pow(10, n) - 1);
//        // 指示res填充到第几位了
//        int resIdx = 0;
//        // 遍历数的位数
//        for (int digit = 1; digit <= n; digit++) {
//            // 遍历最高位的数字
//            for (char first = '1'; first <= '9'; first++) {
//                // 使用dfs从小到大遍历当前位数当前开头的所有组合
//                // 开始：digit位长，只要第一位是first就行，后面的可以覆写
//                string beginStr(1, first);
//                stack<numStruct> s;
//
//                // 开始dfs
//                s.push(numStruct(beginStr, 1));
//                while (!s.empty()) {
//                    numStruct tmp = s.top();
//                    s.pop();
//                    // 当前数构造完毕：加入结果数组
//                    if (digit == tmp.index) {
//                        // cout << tmp.digit << "!!!" << tmp.index << endl;
//                        // cout << atoi(tmp.num.c_str()) << endl;
//                        res[resIdx++] = atoi(tmp.num.c_str());
//                    }
//                    // 未构造完毕：从大到小压栈
//                    else {
//                        for (char first = '9'; first >= '0'; first--) {
//                            s.push(numStruct(tmp.num + string(1, first), tmp.index + 1));
//                        }
//                    }
//                }
//            }
//        }
//        return res;
//    }
//};

int main() {
    cout << "Hello world" << endl;

    Solution solution;
    vector<int> res = solution.printNumbers(1);
    cout << res.size() << endl;

    return 0;
}