/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
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
    bool isEquTree(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2) return true;
        if(!root1 || !root2 || root1->val != root2->val) return false;
        return isEquTree(root1->left, root2->left) && isEquTree(root1->right, root2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && subRoot) return false;
        if(!root && !subRoot) return true;
        bool isEqual = false;
        if (root->val == subRoot->val)
        {
            isEqual = isEquTree(root, subRoot);
        }
        return isEqual || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);

    }
};
// @lc code=end

