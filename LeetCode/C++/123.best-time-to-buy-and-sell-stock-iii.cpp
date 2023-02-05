/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

#include <climits>
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    /** 
     * Accept:  runtime 95.11%
     *          memory 95.24%
     *
     * 重點：使用狀態轉移的 DP
     */
    int maxProfit(vector<int>& prices) {
        int t_hold1 = INT_MIN, t_sold1 = 0, 
            t_hold2 = INT_MIN, t_sold2 = 0;
        for (auto &p: prices) {
            int f_hold1 = t_hold1, f_sold1 = t_sold1,
                f_hold2 = t_hold2, f_sold2 = t_sold2;
            t_hold1 = max(f_hold1, -p);
            t_sold1 = max(f_sold1, f_hold1 + p);
            t_hold2 = max(f_hold2, f_sold1 - p);
            t_sold2 = max(f_sold2, f_hold2 + p);
        }
        return max(t_sold1, t_sold2);
    }
};

// sizeof_collection [all_inputs]
// sizeof_collection [all_outputs]
// sizeof_collection [get_ports]
// 
// logic gate 的輸出都是 Y
// DFF 的輸出都是 Q，比起 Latch 多了 CK (clk)，可以用此特性，用 TCL code 來找 DFF
// 
// get_pins */Q -hier
//
// sizeof_collection [get_pins */Q -hier]
// sizeof_collection [get_pins */CK -hier]
// sizeof_collection [get_cells *reg* -hier]

// @lc code=end

