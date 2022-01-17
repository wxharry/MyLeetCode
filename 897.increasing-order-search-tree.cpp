/*
 * @lc app=leetcode id=897 lang=cpp
 *
 * [897] Increasing Order Search Tree
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
    TreeNode* last=nullptr;
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return root;
        TreeNode* ans = increasingBST(root->left);
        if(last) last->right = root;
        last = root;
        root->left = nullptr;
        root->right = increasingBST(root->right);
        return ans?ans:root;
    }
};
// @lc code=end

