package Java;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode id=102 lang=java
 *
 * [102] Binary Tree Level Order Traversal
 */

// @lc code=start

/* 
 * Authored by Eroiko at 2021/07/26
 * Time : beats 61.7 %
 * Space : beats 79.6 %
 */

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    static class Node {
        TreeNode node;
        int level;
        public Node(TreeNode node, int level){
            this.node = node;
            this.level = level;
        }
    }
    
    public List<List<Integer>> levelOrder(TreeNode root) {
        var res = new ArrayList<List<Integer>>();
        if (root == null){ return res; }
        var q = new ArrayDeque<Node>();
        q.add(new Node(root, 0));
        while (!q.isEmpty()){
            var cur = q.pop();
            ArrayList<Integer> toAdd;
            if (res.size() <= cur.level){
                res.add(toAdd = new ArrayList<>());
            }
            else {
                toAdd = (ArrayList<Integer>) res.get(cur.level);
            }
            toAdd.add(cur.node.val);
            if (cur.node.left != null){
                q.add(new Node(cur.node.left, cur.level + 1));
            }
            if (cur.node.right != null){
                q.add(new Node(cur.node.right, cur.level + 1));
            }
        }
        return res;
    }
}
// @lc code=end

