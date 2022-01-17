/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    unordered_map<int, int> hmap;
    int postIdx;
public:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int left, int right){
        if(left > right) return nullptr;
        int pivot = hmap[postorder[postIdx]];
        TreeNode* node = new TreeNode(inorder[pivot]);
        --postIdx;
        node->right = build(inorder, postorder, pivot+1, right);
        node->left = build(inorder, postorder, left, pivot-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); ++i)
        {
            hmap[inorder[i]] = i;
        }
        postIdx = postorder.size()-1;
        return build(inorder, postorder, 0, postorder.size()-1);
    }
};
// @lc code=end

