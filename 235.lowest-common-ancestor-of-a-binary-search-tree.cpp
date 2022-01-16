/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
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
private:
    TreeNode* p;
    TreeNode* q;
    TreeNode* lca=nullptr;
public:
    // The following method works, but too complicated. I missed the clue that it is a BST.
    // int traverse(TreeNode* root){
    //     if(!root) return 0;
    //     int r=0;
    //     r += traverse(root->left);
    //     r += traverse(root->right);
    //     if(root == p) r += 2;
    //     if(root == q) r += 1;
    //     if(!lca && r == 3){
    //         lca = root;
    //     }
    //     return r;
    // }
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     this->p = p;
    //     this->q = q;
    //     traverse(root);
    //     return this->lca;
    // }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        if(root->val < p->val && root->val < q->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};
// @lc code=end

