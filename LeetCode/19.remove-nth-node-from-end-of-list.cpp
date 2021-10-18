/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/* 
 * Eroiko at 2021/10/15
 * Time : 79.19%, 4ms
 * Spaace : 30.94%, 10.9MB
 */
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next){
            delete head;
            return nullptr;
        }
        ListNode ** lists = new ListNode*[30];
        int sz = 0;
        ListNode * traV = head;
        while (traV){
            lists[sz++] = traV;
            traV = traV->next;
        }
        if (n == sz){
            delete head;
            head = lists[1];
        }
        else {
            lists[sz - n - 1]->next = lists[sz - n]->next;
            delete lists[sz - n];
        }
        delete [] lists;
        return head;
    }
};
// @lc code=end

