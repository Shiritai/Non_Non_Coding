/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start;
        const int len = nums.size();
        for (int i = 0; i < len - 1; ++i) {
            if (nums[i] > nums[i + 1]) { // rotation point
                start = i + 1;
                break;
            }
        }
        int l, r, mid; // [left, right), mid = (l + r) / 2
        if (target >= nums[start] && target <= nums[len - 1]) {
            // search RHS list
            l = start;
            r = len;
        }
        else {
            // search LHS list
            l = 0;
            r = start;
        }
        int strict;
        do {
            strict = r - l;
            int cache;
            if (target == (cache = nums[(mid = ((l + r) >> 1))])) 
                return true;
            else if (target < cache) 
                r = mid;
            else 
                l = mid;
        } while (strict != r - l);
        return false;
    }
};
// @lc code=end

