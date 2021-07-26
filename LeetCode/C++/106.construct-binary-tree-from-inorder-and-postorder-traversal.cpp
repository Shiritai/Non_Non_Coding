/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 */

// @lc code=start

/* 
 * Authored by Eroiko at 2021/07/26
 * Time : beats 45 %
 * Space : beats 84.5 %
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
    TreeNode * buildTree(vector<int>& inorder, vector<int>& postorder) {
        auto postIt = postorder.rbegin();
        return postInBuild(postIt, inorder, 0, inorder.size());
    }

    /* 左閉右開, preorder 指向前一個前序元素 */
    TreeNode * postInBuild(reverse_iterator<vector<int>::iterator> & postorder,
        vector<int> & inorder, int left, int right){
        if (left >= right)
            return nullptr;
        int mid = -1, tmpVal;
        TreeNode * res = new TreeNode((tmpVal = * postorder++));
        for (int i = left; i < right; ++i){
            if (inorder[i] == tmpVal){
                mid = i;
                break;
            }
        }
        if (mid != -1){
            res->right = postInBuild(postorder, inorder, mid + 1, right);
            res->left = postInBuild(postorder, inorder, left, mid);
        }
        return res;
    }
};
// @lc code=end

