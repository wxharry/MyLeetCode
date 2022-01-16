/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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
    int pathSumWithRoot(TreeNode* root, int targetSum){
        if(!root) return 0;
        int count =  root->val == targetSum ? 1 : 0;
        count += pathSumWithRoot(root->left, targetSum-root->val);
        count += pathSumWithRoot(root->right, targetSum-root->val);
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
        {
            return 0;
        }
        return pathSumWithRoot(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};
// @lc code=end

