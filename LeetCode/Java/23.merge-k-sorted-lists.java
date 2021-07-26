package Java;

import java.util.PriorityQueue;

/*
 * @lc app=leetcode id=23 lang=java
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start

/* 
 * Authored by Eroiko at 2021/07/22
 * Time : beats 79.9 %
 * Space : beats 30 %
 */

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0){ return null; }
        var pq = new PriorityQueue<>((ListNode a, ListNode b) -> a.val - b.val);
        for (var l : lists){
            if (l != null){
                pq.add(l);
            }
        }
        if (pq.isEmpty()){ return null; }
        ListNode root = pq.poll(), cur = root;
        if (root.next != null){
            pq.add(root.next);
            cur = root;
        }
        while (!pq.isEmpty()){
            var tmp = pq.poll();
            if (tmp.next != null){ pq.add(tmp.next); }
            cur.next = tmp;
            cur = cur.next;
        }
        return root;
    }
}
// @lc code=end

