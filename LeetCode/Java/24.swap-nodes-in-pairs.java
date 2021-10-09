package Java;
/*
 * @lc app=leetcode id=24 lang=java
 *
 * [24] Swap Nodes in Pairs
 */

// @lc code=start
/* 
 * Time : 100%, 0ms
 * Space : 72.76%, 36.6MB 
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
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null){
            return head;
        }
        ListNode n_head = null;
        ListNode rv, cur = head, nxt = head.next;
        ListNode last_gp_out = cur;
        /* 每次循環, 找到一組並反轉 */
        ListNode traV = cur;
        while (true){
            if (traV.next != null){
                traV = traV.next;
            }
            else { // 終止條件
                last_gp_out.next = cur; // 最後的連接
                break;
            }
            rv = cur;
            cur = nxt;
            nxt = nxt.next;
            cur.next = rv; // reverse

            if (n_head == null){
                n_head = traV;
            }
            else {
                last_gp_out.next = cur;
                last_gp_out = rv;
            }
            last_gp_out.next = null;
            if (nxt == null){ break; }
            traV = cur = nxt;
            nxt = nxt.next;
        }
        return n_head;
    }
}
// @lc code=end

