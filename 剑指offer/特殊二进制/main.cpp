# include<iostream>
# include<vector>
using namespace std;
/* 定义新运算
    从低位到高位，1+1得0进-1
    然后再从低位到高位，修改-1项。-1项后面一项加1，然后-1改为+1
    比如-1~0 -> 1~1, -1~1 -> 1~0~-1
    最后从后往前，消去0*/
vector<int> solution(vector<int>& A, vector<int>& B) {
    // write your code in C++14 (g++ 6.2.0)
    int maxLen = (A.size() > B.size()) ? A.size() : B.size();
    A.resize(maxLen); B.resize(maxLen);
    vector<int> ans(A.size() + 5);

    // 第一遍从头到尾遍历，使用定义新运算法则
    int carry = 0;   // 进位
    for (int i = 0; i < maxLen; i++) {
        switch (A[i] + B[i] + carry) {
        case -1:
            ans[i] = -1;
            carry = 0;
            break;
        case 0:
            ans[i] = 0;
            carry = 0;
            break;
        case 1:
            ans[i] = 1;
            carry = 0;
            break;
        case 2:
            ans[i] = 0;
            carry = -1;
            break;
        }
    }
    ans[maxLen] = carry;

    // 第二次遍历，从头到尾消去-1
    carry = 0;
    for (int i = 0; i < ans.size(); i++) {
        switch (ans[i] + carry) {
        case -1:
            ans[i] = 1;
            carry = 1;
            break;
        case 2:
            ans[i] = 0;
            carry = -1;
            break;
        default:
            ans[i] += carry;
            carry = 0;
            break;
        }
    }

    // 第三次遍历，从尾到头，删去多余的0
    int endPoint = ans.size()-1;
    while (ans[endPoint] == 0) {
        endPoint--;
    }
    ans.resize(endPoint + 1);

    return ans;
}

int main() {
    cout << "Hello world" << endl;
    vector<int> test(2);
    test[0] = 1; test[1] = 2;
    test.push_back(7);  test.push_back(8);
    for (int i = 0; i < 4; i++)
        cout << test[i] << endl;

    cout << endl;
    test.resize(2);
    for (int i = 0; i < 2; i++)
        cout << test[i] << endl;
}