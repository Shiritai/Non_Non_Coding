/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    /** 
     * Accept:  runtime 70.54%
     *          memory 89.63%
     */
    int maxProfit(vector<int>& prices) {
        const int len = prices.size();
        if (len < 2)
            return 0;
        int mn = prices[0], diff = 0;
        for (int i = 1; i < len; ++i) {
            auto p = prices[i];
            if (mn < p)
                diff = max(diff, p - mn);
            else 
                mn = p;
        }
        return diff;
    }
};
// @lc code=end

