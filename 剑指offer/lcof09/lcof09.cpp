/* 剑指 Offer 09. 用两个栈实现队列
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead 
分别完成在队列尾部插入整数和在队列头部删除整数的功能
(若队列中没有元素，deleteHead 操作返回 -1 )*/
# include<iostream>
# include<stack>
using namespace std;

/* 使用双栈实现队列
    主栈进行队尾添加操作，辅助栈实现反序，然后出栈就是出队
    出队时若辅助栈不为空则辅助栈出栈，否则主栈全部倒入辅助栈中后执行出栈。入队直接在主栈中加入即可*/
class CQueue {
    stack<int> mainStack, assStack;
public:
    CQueue() {
        // 初始化为空
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