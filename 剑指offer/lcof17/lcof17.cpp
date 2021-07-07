/* ��ָ Offer 17. ��ӡ��1������nλ��
�������� n����˳���ӡ���� 1 ������ n λʮ���������������� 3�����ӡ�� 1��2��3 һֱ������ 3 λ�� 999*/
# include<iostream>
# include<cmath>
# include<stack>
# include<vector>
# include<string>
using namespace std;

/* ��������10^n - 1�����Ǵ���Խ�����⣬ʹ���ַ�������������
    �������ɣ�һ�����ĸ�λ������һ�����ĸ�λС���������һ������һ����С��һ������λ������һ�����٣���Ҳһ������һ����С
    ʹ��dfs����������ϣ����ɴ�С���������������
    ���һ��ѭ����1��n��������λ��������ÿ��λ����dfs��������ϡ�������λ��Ϊ0����˶�����λ������ʹ��ѭ�����ڶ�λ��ʼ����dfs
    ʹ��ջ���ǵݹ��dfs*/
class Solution {
private:
    class numStruct{
    public:
        string num; // �ַ���������
        int digit;  // ����λ��
        int index;  // ����д�˼�λ�ˣ���������д��λ�����±꣩
        numStruct(string number, int dgt, int idx) {
            num = number;
            digit = dgt;
            index = idx;
        }
    };
public:
    vector<int> printNumbers(int n) {
        vector<int> res(pow(10, n) - 1);
        // ָʾres��䵽�ڼ�λ��
        int resIdx = 0;
        // ��������λ��
        for (int digit = 1; digit <= n; digit++) {
            // �������λ������
            for (char first = '1'; first <= '9'; first++) {
                // ʹ��dfs��С���������ǰλ����ǰ��ͷ���������
                // ��ʼ��digitλ����ֻҪ��һλ��first���У�����Ŀ��Ը�д
                string beginStr(1, first);
                stack<numStruct*> s;

                // ��ʼdfs
                numStruct* beginStruct = new numStruct(beginStr, digit, 1);
                s.push(beginStruct);
                while (!s.empty()) {
                    numStruct* tmp = s.top();
                    s.pop();
                    // ��ǰ��������ϣ�����������
                    if (tmp->digit == tmp->index) {
                        // cout << tmp->digit << "!!!" << tmp->index << endl;
                        // cout << atoi(tmp->num.c_str()) << endl;
                        res[resIdx++] = atoi(tmp->num.c_str());
                    }
                    // δ������ϣ��Ӵ�Сѹջ
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

///* ��������10^n - 1�����Ǵ���Խ�����⣬ʹ���ַ�������������
//    �������ɣ�һ�����ĸ�λ������һ�����ĸ�λС���������һ������һ����С��һ������λ������һ�����٣���Ҳһ������һ����С
//    ʹ��dfs����������ϣ����ɴ�С���������������
//    ���һ��ѭ����1��n��������λ��������ÿ��λ����dfs��������ϡ�������λ��Ϊ0����˶�����λ������ʹ��ѭ�����ڶ�λ��ʼ����dfs
//    ʹ��ջ���ǵݹ��dfs*/
//class Solution {
//private:
//    class numStruct {
//    public:
//        string num; // �ַ���������
//        int digit;  // ����λ��
//        int index;  // ����д�˼�λ�ˣ���������д��λ�����±꣩
//        numStruct(string number, int idx) {
//            num = number;
//            index = idx;
//        }
//    };
//public:
//    vector<int> printNumbers(int n) {
//        vector<int> res(pow(10, n) - 1);
//        // ָʾres��䵽�ڼ�λ��
//        int resIdx = 0;
//        // ��������λ��
//        for (int digit = 1; digit <= n; digit++) {
//            // �������λ������
//            for (char first = '1'; first <= '9'; first++) {
//                // ʹ��dfs��С���������ǰλ����ǰ��ͷ���������
//                // ��ʼ��digitλ����ֻҪ��һλ��first���У�����Ŀ��Ը�д
//                string beginStr(1, first);
//                stack<numStruct> s;
//
//                // ��ʼdfs
//                s.push(numStruct(beginStr, 1));
//                while (!s.empty()) {
//                    numStruct tmp = s.top();
//                    s.pop();
//                    // ��ǰ��������ϣ�����������
//                    if (digit == tmp.index) {
//                        // cout << tmp.digit << "!!!" << tmp.index << endl;
//                        // cout << atoi(tmp.num.c_str()) << endl;
//                        res[resIdx++] = atoi(tmp.num.c_str());
//                    }
//                    // δ������ϣ��Ӵ�Сѹջ
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