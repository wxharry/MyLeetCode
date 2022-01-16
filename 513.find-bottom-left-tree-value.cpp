/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
    void traverse(TreeNode* root, int& maxDepth, int depth, int& value){
        if(!root) return;
        traverse(root->left, maxDepth, depth+1, value);
        traverse(root->right, maxDepth, depth+1, value);
        if (depth > maxDepth)
        {
            value = root->val;
            maxDepth = depth;
        }
        return;
    }

    int findBottomLeftValue(TreeNode* root) {
        // bfs method
        // deque<TreeNode*> level({root});
        // int ans;
        // while (!level.empty())
        // {
        //     int count = level.size();
        //     ans = level.front()->val;
        //     for (int i = 0; i < count; ++i)
        //     {
        //         TreeNode* node = level.front();
        //         level.pop_front();
        //         if(node->left) level.push_back(node->left);
        //         if(node->right) level.push_back(node->right);
        //     }
        // }
        // return ans;

        // dfs method
        int maxDepth=0, ans=root->val;
        traverse(root, maxDepth, 0, ans);
        return ans;
    }
};
// @lc code=end

