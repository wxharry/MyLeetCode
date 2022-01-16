/*
 * @lc app=leetcode id=1110 lang=cpp
 *
 * [1110] Delete Nodes And Return Forest
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
    TreeNode* dfs(TreeNode* root, vector<TreeNode*>& ans, unordered_set<int>& to_delete){
        if (!root)
        {
            return nullptr;
        }
        root->left = dfs(root->left, ans, to_delete);
        root->right = dfs(root->right, ans, to_delete);
        if (to_delete.count(root->val))
        {
            if(root->left)  ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
            delete root;
            return nullptr;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        if(dfs(root, ans, to_delete_set)){
            ans.push_back(root);
        }
        return ans;
    }
};
// @lc code=end

