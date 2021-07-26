/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 */

// @lc code=start

/* 
 * Authored by Eroiko at 2021/07/26
 * Time : beats 65 %
 * Space : beats 67.3 %
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
    TreeNode * buildTree(vector<int> & preorder, vector<int> & inorder) {
        auto preIt = preorder.begin();
        return preInBuild(preIt, inorder, 0, inorder.size());
    }

    /* 左閉右開, preorder 指向前一個前序元素 */
    TreeNode * preInBuild(vector<int>::iterator & preorder, vector<int> & inorder,
        int left, int right){
        if (left >= right)
            return nullptr;
        int mid = -1, tmpVal;
        TreeNode * res = new TreeNode((tmpVal = * preorder++));
        for (int i = left; i < right; ++i){
            if (inorder[i] == tmpVal){
                mid = i;
                break;
            }
        }
        if (mid != -1){
            res->left = preInBuild(preorder, inorder, left, mid);
            res->right = preInBuild(preorder, inorder, mid + 1, right);
        }
        return res;
    }
};
// @lc code=end

