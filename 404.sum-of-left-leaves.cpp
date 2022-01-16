/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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
        // if root has a left leave
        if(root->left && !root->left->left && !root->left->right){
            sum += root->left->val;
        }
        traverse(root->left, sum);
        traverse(root->right, sum);
        return;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans=0;
        traverse(root, ans);
        return ans;
    }
};
// @lc code=end

