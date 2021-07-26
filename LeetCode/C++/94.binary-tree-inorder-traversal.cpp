/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 */

// @lc code=start

/* 
 * Authored by Eroiko at 2021/07/25
 * Time : beats 100 %
 * Space : beats 25.4 %
 */
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inOrder(root, res);
        return res;
    }

private:
    void inOrder(TreeNode * cur, vector<int> &container){
        if (cur){
            inOrder(cur->left, container);
            container.push_back(cur->val);
            inOrder(cur->right, container);
        }
    }
};
// @lc code=end

