/*
 * @lc app=leetcode id=100 lang=c
 *
 * [100] Same Tree
 */

// @lc code=start
/* 
 * Authored by Eroiko at 2021/07/22
 * Time : beats 100 %
 * Space : beats 63.6 %
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if ((p && !q) || (!p && q)) return 0;
    if (p && q){
        if (!isSameTree(p->left, q->left)) return 0;
        if (p->val != q->val) return 0;
        if (!isSameTree(p->right, q->right)) return 0;
    }
    return 1;
}
// @lc code=end

