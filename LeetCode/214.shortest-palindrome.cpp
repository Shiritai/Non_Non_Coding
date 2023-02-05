/*
 * @lc app=leetcode id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool maxOddPalindrome(string &str, int pivot) {
        int _len = str.size() - pivot, 
            len = min(pivot, _len);
        for (int i = 1; i < len; ++i) 
            if (str[pivot - i] != str[pivot + i])
                return false;
        return true;
    }

    bool maxEvenPalindrome(string &str, int pivot_l) {
        int pivot_r = pivot_l + 1;
        int _len = str.size() - pivot_r, 
            len = min(pivot_l, _len);
        for (int i = 0; i < len; ++i) 
            if (str[pivot_l - i] != str[pivot_r + i])
                return false;
        return true;
    }

    string shortestPalindrome(string s) {
        int cur_i, len = s.size(),
            head_end, back_start;
        if (len < 2)
            return s;
        for (cur_i = 0; cur_i < (len >> 1); ++cur_i) {
            if (maxOddPalindrome(s, cur_i)) 
                head_end = ((cur_i + 1) << 1) - 1;
            if (maxOddPalindrome(s, len - cur_i - 1)) 
                back_start = len - ((cur_i + 1) << 1);
            if (maxEvenPalindrome(s, cur_i)) 
                head_end = (cur_i + 1) << 1;
            if (maxEvenPalindrome(s, len - cur_i - 1)) 
                back_start = len - (((cur_i + 1) << 1) - 1);
        }
        string tar;
        if (head_end >= len - back_start) {
            tar = s.substr(head_end);
            tar.reserve();
            return tar + s;
        }
        tar = s.substr(0, back_start);
        tar.reserve();
        return s + tar;
    }
};
// @lc code=end

