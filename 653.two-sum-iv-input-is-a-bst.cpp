/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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
    void traverse(TreeNode* root){
        if(!root) return;
        traverse(root->left);
        inorder.push_back(root->val);
        traverse(root->right);
        return;
    }
public:
    bool findTarget(TreeNode* root, int k) {
        traverse(root);
        int l=0, r=inorder.size()-1;
        while (l < r)
        {
            int sum = inorder[l] + inorder[r];
            if(sum == k){
                return true;
            }
            else if (sum > k)
            {
                --r;
            }
            else if (sum < k)
            {
                ++l;
            }
        }
        return false;
    }
};
// @lc code=end

