/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& rootIndex, int left, int right, unordered_map<int, int>& premap){
        if (left > right || rootIndex >= preorder.size())
        {
            return nullptr;
        }
        
        int pivot = premap[preorder[rootIndex]];
        TreeNode* node = new TreeNode(preorder[rootIndex]);
        ++rootIndex;
        node->left = build(preorder, inorder, rootIndex, left, pivot-1, premap);
        node->right = build(preorder, inorder, rootIndex, pivot+1, right, premap);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> premap;
        for (int i = 0; i < inorder.size(); ++i)
        {
            premap[inorder[i]] = i;
        }
        int rootIndex = 0;
        return build(preorder, inorder, rootIndex, 0, inorder.size()-1, premap);
    }
};
// @lc code=end

