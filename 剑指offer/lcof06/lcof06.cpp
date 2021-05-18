/* ��ָ Offer 06. ��β��ͷ��ӡ����
����һ�������ͷ�ڵ㣬��β��ͷ����������ÿ���ڵ��ֵ�������鷵�أ���*/
# include<iostream>
# include<vector>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 /* �͵����ã�Ȼ���ӡ*/
 class Solution {
 public:
     vector<int> reversePrint(ListNode* head) {
         if (head == NULL)   return vector<int>(0);

         // �Ⱦ͵�����
         // ����ͷ�ڵ㣬������
         ListNode* emptyHead = new ListNode(-1);
         emptyHead->next = head;
         // pָ��ǰҪ���õĽڵ㣬q�洢p.next��ϵ
         ListNode* p = emptyHead->next, *q;
         int count = 0;
         while (p != NULL) {
             count++;
             // �����ϵ
             q = p->next;
             // ����
             p->next = emptyHead->next;
             emptyHead->next = p;
             // ����
             p = q;
         }

         // ��ӡ
         vector<int> ans(count);
         ListNode* prt = emptyHead->next;
         for (int i = 0; i < count; i++) {
             ans[i] = prt->val;
             prt = prt->next;
         }

         return ans;
     }
 };

 int main() {
     cout << "Hello world" << endl;

     ListNode v1(1), v2(2), v3(3);
     v1.next = &v2; v2.next = &v3;

     Solution test;
     vector<int> ans =  test.reversePrint(&v1);
     for (int i = 0; i < 3; i++) {
         cout << ans[i] << endl;
     }
 }
 