/*
 * @lc app=leetcode id=98 lang=c
 *
 * [98] Validate Binary Search Tree
 */

/* 
 * Authored by Eroiko at 2021/07/22
 * Time : beats 74.6 %
 * Space : beats 90.3 %
 */
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// # include <stdio.h>
// # include <stdbool.h>

// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };

static int inOrder(struct TreeNode *);

static long long last;

bool isValidBST(struct TreeNode * root){
    last = -2147483649;
    return inOrder(root);
}

static int inOrder(struct TreeNode * cur){
    if (cur){
        if (!inOrder(cur->left)) return 0;
        if (cur->val <= last) return 0;
        last = cur->val;
        if (!inOrder(cur->right)) return 0;
    }
    return 1;
}

// int main(void){
//     struct TreeNode tmp = {.val = 0, .left = NULL, .right = NULL};
//     printf("%d\n", isValidBST(&tmp));
// }
// @lc code=end

