/* ��ָ Offer 07. �ؽ�������
����ĳ��������ǰ���������������Ľ�������ؽ��ö����������������ǰ���������������Ľ���ж������ظ������֡�*/
# include<iostream>
# include<vector>
# include<map>
using namespace std;


//Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
 /* �����ǰ������������ؽ���
ͨ����ǰ������б�ȷ�������ڵ� (root)��
������������б��Ľڵ�ָ�ɡ����֧�ڵ㡿�͡��ҷ�֧�ڵ㡿
�ݹ�Ѱ�ҡ����֧�ڵ㡿�еġ����ڵ� (left child)���� ���ҷ�֧�ڵ㡿�еġ����ڵ� (right child)��
ʹ�ù�ϣ��洢�������λ����ֵ�Ĺ�ϵ������ٶ�
 */
class Solution {
private:
    // �洢�������������������й�ϣ���������
    vector<int> pre;
    map<int, int> map;

    // �ڲ�ݹ麯�����ݹ齨��
    TreeNode* build(int root, int left, int right) {
        // �ݹ��˳�����
        if (left > right)    return NULL;
        
        // ���ڵ�
        TreeNode* node = new TreeNode(pre[root]);
        // �����������л���
        int midLoc = map.find(pre[root])->second;
        // ����
        node->left = build(root + 1, left, midLoc - 1);
        node->right = build(root + (midLoc - left) + 1, midLoc + 1, right);
        return node;
    }
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // ��ʼ��
        pre = preorder;
        for (int i = 0; i < inorder.size(); i++) {
            map.insert(pair<int, int>(inorder[i], i));
        }
        // �ݹ齨��
        return build(0, 0, preorder.size() - 1);
	}
};

int main() {
    int l1[5] = { 3, 9, 20, 15, 7 };
    int l2[5] = { 9, 3, 15, 20, 7 };
    vector<int> pre(5), mid(5);
    for (int i = 0; i < 5; i++) {
        pre[i] = l1[i];
        mid[i] = l2[i];
    }

    Solution test;
    test.buildTree(pre, mid);
}