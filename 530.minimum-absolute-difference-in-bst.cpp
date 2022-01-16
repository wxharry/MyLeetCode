/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute minDifference in BST
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
    void traverse(TreeNode* root, int& minDiff, int& value){
        if(!root) return;
        traverse(root->left, minDiff, value);
        if(value != -1){
            minDiff = min(minDiff, root->val - value);
        }
        value = root->val;
        traverse(root->right, minDiff, value);
        return;
    }

    int getMinimumDifference(TreeNode* root) {
        int minDiff=INT_MAX, value=-1;
        traverse(root, minDiff, value);
        return minDiff;
    }
};
// @lc code=end

