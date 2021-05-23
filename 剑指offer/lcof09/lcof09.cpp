/* ��ָ Offer 09. ������ջʵ�ֶ���
������ջʵ��һ�����С����е��������£���ʵ�������������� appendTail �� deleteHead 
�ֱ�����ڶ���β�������������ڶ���ͷ��ɾ�������Ĺ���
(��������û��Ԫ�أ�deleteHead �������� -1 )*/
# include<iostream>
# include<stack>
using namespace std;

/* ʹ��˫ջʵ�ֶ���
    ��ջ���ж�β��Ӳ���������ջʵ�ַ���Ȼ���ջ���ǳ���
    ����ʱ������ջ��Ϊ������ջ��ջ��������ջȫ�����븨��ջ�к�ִ�г�ջ�����ֱ������ջ�м��뼴��*/
class CQueue {
    stack<int> mainStack, assStack;
public:
    CQueue() {
        // ��ʼ��Ϊ��
        if (!mainStack.empty()) {
            mainStack.pop();
        }
        if (!assStack.empty()) {
            assStack.pop();
        }
    }

    void appendTail(int value) {
        mainStack.push(value);
    }

    int deleteHead() {
        if (assStack.empty()) {
            if (mainStack.empty()) {
                return -1;
            }
            else {
                while (!mainStack.empty()) {
                    assStack.push(mainStack.top());
                    mainStack.pop();
                }
            }
        }
        int tmp = assStack.top();
        assStack.pop();
        return tmp;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main() {
    cout << "Hello world" << endl;
}