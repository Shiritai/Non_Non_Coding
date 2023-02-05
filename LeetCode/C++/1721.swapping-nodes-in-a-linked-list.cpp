/*
 * @lc app=leetcode id=1721 lang=cpp
 *
 * [1721] Swapping Nodes in a Linked List
 */

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include <iostream>
#include <deque>
using namespace std;

// @lc code=start
class Solution {
public:
    /** 
     * Accept: runtime 63.34%
     *          memory  7.92%
     */
    ListNode* swapNodes(ListNode* head, int k) {
        deque<ListNode*> ls;
        auto hyper = head;
        for (int i = 1; i < k; ++i) {
            ls.push_back(hyper);
            hyper = hyper->next;
        }
        ls.push_back(hyper);
        auto lhs = hyper;
        
        hyper = hyper->next;
        while (hyper) {
            ls.pop_front();
            ls.push_back(hyper);
            hyper = hyper->next;
        }
        auto rhs = *ls.begin();
        swap(lhs->val, rhs->val);
        return head;
    }
};

// @lc code=end
int main(void){
    
}

