/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
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
    void traverse(TreeNode* root, int x, int y, map<int, map<int, multiset<int> > >& coodinate){
        if(!root) return;
        coodinate[x][y].insert(root->val);
        traverse(root->left, x-1, y+1, coodinate);
        traverse(root->right, x+1, y+1, coodinate);
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int> > > coodinate;
        traverse(root, 0, 0, coodinate);
        vector<vector<int> > ans;
        for (auto &node : coodinate)
        {
            vector<int> col;
            for (auto &c : node.second)
            {
                col.insert(col.end(), c.second.begin(), c.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
// @lc code=end

