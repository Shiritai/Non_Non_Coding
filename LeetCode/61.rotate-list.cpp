/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 */

// @lc code=start
/* 
 * Time : 100%, 0ms
 * Space : 53.79%, 11.7MB
 */

# include <iostream>
using namespace std;
/**
 * Singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode * rotateRight(ListNode * head, int k) {
        if (!head || !k || !head->next)
            return head;
        int len = 0;
        ListNode * cur = head, * prev = nullptr;
        do {
            cur = cur->next;
            ++len;
        } while (cur->next);
        ++len;
        int move = (((len - k) % len) + len) % len;
        if (move){
            cur->next = head;
            cur = head;
            while (move--){
                prev = cur;
                cur = cur->next;
            }
            if (prev)
                prev->next = nullptr;
            return cur;
        }
        return head; // don't need to rotate!
    }
};

int main(){
    ListNode * head = new ListNode(1), * cur = head;
    int from = 1, to = 2;
    for (int i = from + 1; i <= to; ++i, cur = cur->next)
        cur->next = new ListNode(i);
    cur = Solution().rotateRight(head, 2);
    for (int i = from; i <= to; ++i, cur = cur->next)
        cout << cur->val << ' ';
    cout << endl;
    cur = head;
    for (int i = from; i <= to; ++i){
        ListNode * prev = cur;
        cur = cur->next;
        delete prev;
    }
}
// @lc code=end

