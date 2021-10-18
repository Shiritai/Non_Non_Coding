/*
 * @lc app=leetcode id=1721 lang=cpp
 *
 * [1721] Swapping Nodes in a Linked List
 */

// @lc code=start
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
# include <iostream>
using namespace std;
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (!head->next)
            return head;
        ListNode * cur = head, * ll, * lr, * rl = head, * rr;
        int cnt = 0;
        while (cur){
            if (cnt == k - 2)
                ll = cur;
            if (cnt == k)
                lr = cur;
            if (cnt > k)
                rl = rl->next;
            cur = cur->next;
            ++cnt;
        }
        /* lr, rl must have been initialized */
        ListNode * l, *r;
        r = rl->next;
        if (rl->next == lr){ // k * 2 == size (i.e. cnt)
            l = rl, r = lr;
            l->next = r->next;
            r->next = l;
            if (k != 1)
                ll->next = r;
            else 
                head = r;
        }
        else 
        if (k == 1){
            /* init l */
            l = head;
            /* Assign pointers */
            r->next = lr;
            rl->next = l;
            /* New head */
            head = r;
            l->next = nullptr; // or the end of list will be a loop! 
        }
        else {
            /* init l, rr */
            l = ll->next;
            rr = rl->next->next;
            /* Assign pointers */
            r->next = lr;
            ll->next = r;
            l->next = rr;
            rl->next = l;
        }
        // cout << "ll : " << ll->val << endl;
        // cout << "lr : " << lr->val << endl;
        // cout << "rl : " << rl->val << endl;
        // cout << "rr : " << rr->val << endl;
        return head;
    }
};

int main(void){
    int to = 10;
    ListNode * head = new ListNode(1), * cur = head;
    for (int i = 2; i <= to; ++i){
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    ListNode * got = Solution().swapNodes(head, 7);
    for (ListNode * i = got; i; i = i->next)
        cout << i->val << " ";
    cout << endl;
    for (int i = 1; i <= to; ++i){
        ListNode * to_del = cur;
        cur = cur->next;
        delete to_del;
    }
}
// @lc code=end

