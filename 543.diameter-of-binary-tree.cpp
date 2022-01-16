/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int helper(TreeNode* root, int& diameter){
        if (!root)
        {
            return 0;
        }
        int l=helper(root->left, diameter), r=helper(root->right, diameter);
        diameter = max(l + r, diameter);
        return max(l, r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        helper(root, d);
        return d;
    }
};
// @lc code=end

