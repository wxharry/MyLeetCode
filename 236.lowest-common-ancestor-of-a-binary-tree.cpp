/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
TreeNode* lca;
public:

    // int dfs(TreeNode* root, TreeNode* p, TreeNode* q){
    //     if(!root) return 0;
    //     int r=0;
    //     r += dfs(root->left, p, q);
    //     r += dfs(root->right, p, q);
    //     if(root->val == p->val) r += 2;
    //     if(root->val == q->val) r += 1;
    //     if(!lca && r == 3){
    //         lca = root;
    //     }
    //     return r;
    // }
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     lca=nullptr;
    //     dfs(root, p, q);
    //     return lca;
    // }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(!left && !right) return nullptr;
        if(left && right) return root;
        return left ? left : right;
    }
};
// @lc code=end

