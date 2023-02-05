/*
 * @lc app=leetcode id=719 lang=cpp
 *
 * [719] Find K-th Smallest Pair Distance
 */

// #include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
/** 
 * Accept: runtime 5.11% (very bad)
 *          memory 5.74% (very bad)
 */
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        const int len = nums.size(), 
                  longest = nums.back() - nums.front() + 1;
        vector<int> table(longest, 0);
        int max_val;
        for (int i = 0; i < len - 1; ++i) 
            for (int j = i + 1; j < len; ++j) 
                ++table[abs(nums[i] - nums[j])];
        for (int i = 0, tb_len = table.size(); i < tb_len; ++i) {
            k -= table[i];
            if (k <= 0)
                return i;
        }
        return -1;
    }
};
// @lc code=end

