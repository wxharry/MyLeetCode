/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    int helper(TreeNode* root){
        if (!root)
        {
            return 0;
        }
        int left = helper(root->left), right = helper(root->right);
        if (left == -1 || right == -1 || abs(left-right) > 1)
        {
            return -1;
        }
        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        return helper(root) != -1;
    }
};
// @lc code=end

