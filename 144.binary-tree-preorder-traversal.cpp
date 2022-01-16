/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    // recursive solution
    // void preorderTraversalHelper(TreeNode* root, vector<int>&sequence){
    //     if(!root) return;
    //     sequence.push_back(root->val);
    //     preorderTraversalHelper(root->left, sequence);
    //     preorderTraversalHelper(root->right, sequence);
    //     return;
    // }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     preorderTraversalHelper(root, ans);
    //     return ans;
    // }

    // follow up: iterative solution
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        vector<TreeNode*> s({root});
        while (!s.empty())
        {
            TreeNode* p = s.back();
            s.pop_back();
            ans.push_back(p->val);
            if(p->right) s.push_back(p->right);
            if(p->left) s.push_back(p->left);
        }
        return ans;
    }
};
// @lc code=end

