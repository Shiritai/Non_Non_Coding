package Java;
/*
 * @lc app=leetcode id=25 lang=java
 *
 * [25] Reverse Nodes in k-Group
 */

// @lc code=start
/* 
 * Time : 100%, 0ms
 * Space : 61.29%, 39.3MB
 */
/**
 * Definition for singly-linked list.
 */
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head.next == null || k == 1){
            return head;
        }
        ListNode n_head = null;
        ListNode rv, cur = head, nxt = head.next;
        ListNode last_gp_out = cur;
        int total = 0;
        /* 每次循環, 找到一組並反轉 */
        ListNode traV = cur;
        while (true){
            int cnt = 1;
            while (traV.next != null && cnt != k){
                traV = traV.next;
                ++cnt;
            }
            if (cnt != k){ // 終止條件
                last_gp_out.next = cur; // 最後的連接
                break;
            }
            else { // 反轉 linked list
                total += cnt;
                System.out.println("Current at no." + total + " with value " + traV.val);
                boolean get_out = false;
                ListNode this_out = null;
                do {
                    rv = cur;
                    cur = nxt;
                    nxt = nxt.next;
                    cur.next = rv; // reverse
                    if (!get_out){
                        this_out = rv;
                        get_out = true;
                    }
                } while (cur != traV);

                if (n_head == null){
                    n_head = traV;
                }
                else {
                    last_gp_out.next = cur;
                    last_gp_out = this_out;
                }
                last_gp_out.next = null;
                
                System.out.println("---------------------");
                ListNode test = cur;
                int tmp = 0;
                while (test != null && tmp < k + 1){
                    System.out.println(test.val);
                    test = test.next;
                    ++tmp;
                }
                System.out.println("---------------------");
                
                System.out.println("Next value is " + ((nxt != null) ? nxt.val : "null"));
                if (nxt == null){ break; }
                traV = cur = nxt;
                nxt = nxt.next;
            }
        }
        System.out.println("---------------------");
        ListNode test = n_head;
        while (test != null){
            System.out.println(test.val);
            test = test.next;
        }
        System.out.println("---------------------");
        return n_head;
    }
}

// @lc code=end

