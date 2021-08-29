/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start

/* 
 * Authored by Eroiko at 2021/08/06
 * Time : beats 46.6 %
 * Space : beats 67.2 %
 */

# include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros, ones, twos;
        zeros = ones = twos = 0;
        for (auto i : nums){
            if (!i) ++zeros;
            else if (i == 1) ++ones;
            else ++twos;
        }
        int ind = 0, size = nums.size();
        while (ind < size){
            if (zeros){
                --zeros;
                nums[ind++] = 0;
            }
            else if (ones){
                --ones;
                nums[ind++] = 1;
            }
            else {
                --twos;
                nums[ind++] = 2;
            }
        }
    }
};
// @lc code=end

