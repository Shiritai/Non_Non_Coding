/*
 * @lc app=leetcode id=101 lang=c
 *
 * [101] Symmetric Tree
 */

// @lc code=start

/* 
 * Authored by Eroiko at 2021/07/22
 * Time : beats 75 %
 * Space : beats 74.8 %
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSymTree(struct TreeNode * p, struct TreeNode * q){
    if ((p && !q) || (!p && q)) return 0;
    if (p && q){
        if (!isSymTree(p->left, q->right)) return 0;
        if (p->val != q->val) return 0;
        if (!isSymTree(p->right, q->left)) return 0;
    }
    return 1;
}

bool isSymmetric(struct TreeNode* root){
    return isSymTree(root->left, root->right);
}
// @lc code=end

