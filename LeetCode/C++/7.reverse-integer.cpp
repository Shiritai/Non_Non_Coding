/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
/* 
 * Authored by Eroiko at 2021/07/22
 * Space : beats 6.6 %
 * Time : beats 100 %
 */

# include <string>
# include <algorithm>

class Solution {
public:
    int reverse(int x) {
        try {
            if (x == 0x80000000) return 0;
            int sign = x >= 0 ? 1 : -1;
            auto str = std::to_string(abs(x));
            std::reverse(str.begin(), str.end());
            return stoi(((sign == 1) ? str : "-" + str));
        } catch (std::exception & e){ // means out of range
            return 0;
        }
    }
};
// @lc code=end

