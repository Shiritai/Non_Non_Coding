/*
 * @lc app=leetcode id=104 lang=c
 *
 * [104] Maximum Depth of Binary Tree
 */

// @lc code=start

/* 
 * Authored by Eroiko at 2021/07/26
 * Time : beats 92.7 %
 * Space : beats 92.9 %
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static inline int max(int a, int b){ return a > b ? a : b; }

static int preOrder(struct TreeNode * cur, int currentMaxLevel){
    if (cur){
        return max(
            preOrder(cur->left, currentMaxLevel + 1),
            preOrder(cur->right, currentMaxLevel + 1)
        );
    }
    return currentMaxLevel;
}

int maxDepth(struct TreeNode* root){
    return preOrder(root, 0);
}

// @lc code=end

