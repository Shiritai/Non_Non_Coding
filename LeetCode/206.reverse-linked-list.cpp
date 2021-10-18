/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

/* 
 * Time : 7.86%, 14ms
 * Space : 41.51%, 8.4MB
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode * cur = head, * next = cur->next, *r;
        while (next){
            r = cur;
            cur = next;
            next = next->next;
            cur->next = r;
        }
        head->next = NULL;
        return cur;
    }
};
// @lc code=end

