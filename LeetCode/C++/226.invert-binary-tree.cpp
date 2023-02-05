/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
 */

/**
 * Definition for a binary tree node.
 */
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right; 
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
using namespace std;
// @lc code=start
class Solution {
public:
    /** 
     * Version 1
     * Accept: runtime 100%
     *          memory 5.8%
     */
    TreeNode* invertTree(TreeNode* root) {
        if (root) {
            std::swap(root->left, root->right);
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
    
    /** 
     * Version 2
     * Accept: runtime 100%
     *          memory 38.36%
     */
    // TreeNode* _invertTree(TreeNode* cur) {
    //     std::swap(cur->left, cur->right);
    //     if (cur->left)
    //         invertTree(cur->left);
    //     if (cur->right)
    //         invertTree(cur->right);
    //     return cur;
    // }
     
    // TreeNode* invertTree(TreeNode* root) {
    //     if (!root)
    //         return nullptr;
    //     _invertTree(root);
    //     return root;
    // }
    
    /** 
     * Version 3
     * Accept: runtime 70.46%
     *          memory 38.s6%
     */
    // TreeNode* invertTree(TreeNode* root) {
    //     vector<TreeNode*> st;
    //     TreeNode * cur;
    //     st.push_back(root);
    //     while (!st.empty()) {
    //         cur = st.back();
    //         st.pop_back();
    //         if (cur) {
    //             std::swap(cur->left, cur->right);
    //             st.push_back(cur->left);
    //             st.push_back(cur->right);
    //         }
    //     }
    //     return root;
    // }
    
    /** 
     * Version 4
     * Accept: runtime 70.46%
     *          memory 79.76%
     */
    // TreeNode* invertTree(TreeNode* root) {
    //     vector<TreeNode*> st;
    //     TreeNode * cur;
    //     st.push_back(root);
    //     while (!st.empty()) {
    //         cur = st.back();
    //         st.pop_back();
    //         if (cur) {
    //             std::swap(cur->left, cur->right);
    //             if (cur->left)
    //                 st.push_back(cur->left);
    //             if (cur->right)
    //                 st.push_back(cur->right);
    //         }
    //     }
    //     return root;
    // }
};
// @lc code=end

