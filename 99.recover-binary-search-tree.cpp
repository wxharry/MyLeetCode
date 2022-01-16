/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* first=nullptr;
    TreeNode* second=nullptr;
    TreeNode* prev = new TreeNode(INT_MIN);
    void findNodes(TreeNode* root){
        if(!root) return;
        findNodes(root->left);
        if(!first && prev->val > root->val) first = prev;
        if(first && prev->val > root->val) second = root;
        prev = root;
        findNodes(root->right);
        return;
    }
    void recoverTree(TreeNode* root) {
        findNodes(root);
        swap(first->val, second->val);
        return;
    }
};
// @lc code=end

