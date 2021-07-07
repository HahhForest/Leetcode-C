/* ��ָ Offer 18. ɾ������Ľڵ�
�������������ͷָ���һ��Ҫɾ���Ľڵ��ֵ������һ������ɾ���ýڵ㡣

����ɾ����������ͷ�ڵ㡣*/
# include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* front = new ListNode(0);
        front->next = head;
        ListNode* p = front, * q = p->next;
        
        while (q != NULL) {
            if (q->val == val) {
                p->next = q->next;
                delete q;
                break;
            }
            p = p->next;
            q = q->next;
        }
        return front->next;
    }
};

int main() {
    cout << "Hello world" << endl;
    ListNode n1(-3), n2(3), n3(10);
    n1.next = &n2;   n2.next = &n3;
    
    Solution solution;
    ListNode* res = solution.deleteNode(&n1, -3);
}