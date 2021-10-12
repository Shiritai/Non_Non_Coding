/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/* 
 * Eroiko, at 2021/10/13
 * Time : 23.76 % (18ms)
 * Space : 58.70% (8.1MB)
 */
class Solution {
public:
    /* Floyd linked-list cycle detection Algorithm */
    bool hasCycle(ListNode *head) {
        if (!head || !head->next)
            return false;
        ListNode * f = head->next, * s = head;
        while (f && f->next){
            if (f == s)
                return true;
            f = f->next->next;
            s = s->next;
        }
        return false;
    }
};
// @lc code=end

