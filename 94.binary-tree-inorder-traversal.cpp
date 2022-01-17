/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorder;
public:
    void traverse(TreeNode* root){
        if(!root) return;
        traverse(root->left);
        inorder.push_back(root->val);
        traverse(root->right);
        return;
    }
    void traverse_iterative(TreeNode* root){
        vector<TreeNode*> st;
        TreeNode* node = root;
        while (node || !st.empty())
        {
            if (node){
                st.push_back(node);
                inorder.push_back(node->val);
                node = node->left;
            }
            else{
                node = st.back();
                st.pop_back();
                node = node->right;
            }
        }
        
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        // traverse(root);
        traverse_iterative(root);
        return inorder;
    }
};
// @lc code=end

