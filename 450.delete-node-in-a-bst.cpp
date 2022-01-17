/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        TreeNode* ans;
        if(root->val == key){
            if(!root->left){
                ans = root->right;
                delete root;
                return ans;
            }
            TreeNode* node = root->left;
            ans = node;
            while (node->right)
            {
                node = node->right;   
            }
            node ->right = root->right;
            delete root;
            return ans;
        }
        else if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};
// @lc code=end

