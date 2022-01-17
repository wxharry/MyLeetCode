/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorder;
public:
    void traverse(TreeNode* root){
        if(!root) return;
        traverse(root->left);
        traverse(root->right);
        postorder.push_back(root->val);
    }
    // The key point is when you pop a node from stack, you ensure you have already explored its children.
    void traverse_iterative(TreeNode* root){
        vector<TreeNode*> st;
        TreeNode* node = root, *last=nullptr;
        while (node || !st.empty())
        {
            if (node)
            {
                st.push_back(node);
                node = node->left;
            }
            else
            {
                node = st.back();
                if(node->right && node->right != last){
                    node = node->right;
                }
                else
                {
                    postorder.push_back(node->val);
                    last = node;
                    node = nullptr;
                    st.pop_back();
                }                
            }
            

        }
        
    }
    vector<int> postorderTraversal(TreeNode* root) {
        // traverse(root);
        traverse_iterative(root);
        return postorder;
    }
};
// @lc code=end

