/* 剑指 Offer 06. 从尾到头打印链表
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。*/
# include<iostream>
# include<vector>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 /* 就地逆置，然后打印*/
 class Solution {
 public:
     vector<int> reversePrint(ListNode* head) {
         if (head == NULL)   return vector<int>(0);

         // 先就地逆置
         // 辅助头节点，无数据
         ListNode* emptyHead = new ListNode(-1);
         emptyHead->next = head;
         // p指向当前要逆置的节点，q存储p.next关系
         ListNode* p = emptyHead->next, *q;
         int count = 0;
         while (p != NULL) {
             count++;
             // 保存关系
             q = p->next;
             // 逆置
             p->next = emptyHead->next;
             emptyHead->next = p;
             // 迭代
             p = q;
         }

         // 打印
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
 