/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
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
    void traverse(TreeNode* root, int& sum){
        if(!root) return;
        traverse(root->right, sum);
        sum += root->val;
        root->val = sum;
        traverse(root->left, sum);
        return;
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        traverse(root, sum);
        return root;
    }
};
// @lc code=end

