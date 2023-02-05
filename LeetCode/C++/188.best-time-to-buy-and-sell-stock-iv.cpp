/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

#include <algorithm>
#include <climits>
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    /** 
     * Accept: runtime: 92.83%
     *          memory: 94.1 %
     */
    int maxProfit(int k, vector<int>& prices) {
        if (!k)
            return 0;
        
        vector<int> hold(k, INT_MIN), sold(k, 0);
        for (auto &p: prices) {
            hold[0] = max(hold[0], -p);
            sold[0] = max(sold[0], hold[0] + p);
            for (int i = 1; i < k; ++i) {
                hold[i] = max(hold[i], sold[i - 1] - p);
                sold[i] = max(sold[i], hold[i] + p);
            }
        }
        return *max_element(sold.begin(), sold.end());
    }
};
// @lc code=end

