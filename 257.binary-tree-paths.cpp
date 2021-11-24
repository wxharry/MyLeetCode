/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    vector<string> binaryTreePaths(TreeNode* root) {
        queue <TreeNode*> q({root});
        deque<string> paths({""});
        vector<string> ans;
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            auto path = paths.front();
            paths.pop_front();
            if (node == root)
            {
                path = to_string(node->val);
            }
            else
            {
                path += "->"+to_string(node->val);
            }
            if (node->left == nullptr && node->right == nullptr)
            {
                ans.push_back(path);
            }
            
            if (node->left != nullptr)
            {
                q.push(node->left);
                paths.push_back(path);
            }
            if (node->right != nullptr)
            {
                q.push(node->right);
                paths.push_back(path);
            }
            
        }
        return ans;
    }
};
// @lc code=end

