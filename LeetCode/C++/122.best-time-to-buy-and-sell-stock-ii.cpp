/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    /** 
     * Accept:  runtime 85.72%
     *          memory 89.51%
     */
    int maxProfit(vector<int>& prices) {
        const int len = prices.size();
        if (len < 2)
            return 0;
        int mn = prices[0], mx = mn, res = 0;
        for (int i = 1; i < len; ++i) {
            auto p = prices[i];
            if (mx < p)
                mx = max(mx, p);
            else {
                res += mx - mn;
                mx = mn = p;
            }
        }
        return res + mx - mn;
    }
};
// @lc code=end

