/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 */

// @lc code=start

/* 
 * Authored by Eroiko at 2021/07/26
 * Time : beats 48.9 %
 * Space : beats 54.3 %
 */

# include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        /* 左閉右開 */
        int odd = nums.size(), even = 0;
        while (odd > even){
            if (nums[even] & 1) // odd
                swap(nums[--odd], nums[even]);
            else
                ++even;
        }
        return nums;
    }
};
// @lc code=end

