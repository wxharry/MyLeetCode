/*
 * @lc app=leetcode id=889 lang=cpp
 *
 * [889] Construct Binary Tree from Preorder and Postorder Traversal
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
    int preIndex=0;
    int postIndex=0;
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* node = new TreeNode(preorder[preIndex]);
        ++preIndex;
        if (node->val != postorder[postIndex])
        {
            node->left = constructFromPrePost(preorder, postorder);
        }
        if (node->val != postorder[postIndex])
        {
            node->right = constructFromPrePost(preorder, postorder);
        }
        ++postIndex;
        return node;
    }
};
// @lc code=end

