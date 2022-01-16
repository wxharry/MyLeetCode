/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
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
    vector<double> averageOfLevels(TreeNode* root) {
        TreeNode *p;
        deque<TreeNode*> layer({root});
        double sum=0, count=0;
        vector<double> ans;
        int i=0;
        while (!layer.empty())
        {
            count = layer.size();
            for (int i = 0; i < count; ++i)
            {
                p = layer.front();
                layer.pop_front();
                sum += p->val;
                if(p->left) layer.push_back(p->left);
                if(p->right) layer.push_back(p->right);
            }
            ans.push_back(sum/count);
            sum=0;
        }
        
        return ans;
    }
};
// @lc code=end

