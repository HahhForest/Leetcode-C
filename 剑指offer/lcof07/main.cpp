/* 剑指 Offer 07. 重建二叉树
输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。*/
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
 
 /* 经典从前序和中序序列重建树
通过【前序遍历列表】确定【根节点 (root)】
将【中序遍历列表】的节点分割成【左分支节点】和【右分支节点】
递归寻找【左分支节点】中的【根节点 (left child)】和 【右分支节点】中的【根节点 (right child)】
使用哈希表存储中序遍历位置与值的关系，提高速度
 */
class Solution {
private:
    // 存储先序遍历数组和中序序列哈希表，方便调用
    vector<int> pre;
    map<int, int> map;

    // 内层递归函数，递归建树
    TreeNode* build(int root, int left, int right) {
        // 递归退出条件
        if (left > right)    return NULL;
        
        // 根节点
        TreeNode* node = new TreeNode(pre[root]);
        // 在中序序列中划分
        int midLoc = map.find(pre[root])->second;
        // 分治
        node->left = build(root + 1, left, midLoc - 1);
        node->right = build(root + (midLoc - left) + 1, midLoc + 1, right);
        return node;
    }
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 初始化
        pre = preorder;
        for (int i = 0; i < inorder.size(); i++) {
            map.insert(pair<int, int>(inorder[i], i));
        }
        // 递归建树
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