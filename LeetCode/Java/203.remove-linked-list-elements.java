import java.util.List;

/*
 * @lc app=leetcode id=203 lang=java
 *
 * [203] Remove Linked List Elements
 */

// @lc code=start
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
    public ListNode removeElements(ListNode head, int val) {
        ListNode cur, tmp, prev = null;
        while (head != null && head.val == val){ // 去頭
            prev = head;
            head = head.next;
            prev.next = null;
        }
        if (head == null)
            return null;
        cur = head;
        while (cur != null){ // 去身去尾
            if (cur.val == val){
                cur = cur.next;
                tmp = prev.next;
                prev.next = cur;
                tmp.next = null;
            }
            else {
                prev = cur;
                cur = cur.next;
            }
        }
        return head;
    }
}
// @lc code=end

