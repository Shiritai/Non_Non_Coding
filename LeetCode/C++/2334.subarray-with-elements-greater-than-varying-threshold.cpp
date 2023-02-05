/*
 * @lc app=leetcode id=2334 lang=cpp
 *
 * [2334] Subarray With Elements Greater Than Varying Threshold
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        nums.insert(nums.begin(), 0);
        nums.push_back(0);
        const int sz = nums.size();
        vector<int> st;
        st.reserve(sz);
        
        for (int i = 0, val; i < sz; ++i) {
            while (!st.empty() && (val = nums[st.back()]) > nums[i]) {
                st.pop_back();
                int to = st.back(), 
                    diff = i - to - 1;
                if (val * diff > threshold)
                    return diff;
            }
            st.push_back(i);
        }
        return -1;
    }
};
// @lc code=end

