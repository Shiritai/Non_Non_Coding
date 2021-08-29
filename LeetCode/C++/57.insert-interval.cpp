/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
/* 
 * Authored by Eroiko at 2021/08/28
 * Time : beats 91.2 %
 * Space : beats 41.6 %
 */
# include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (!intervals.size())
            return vector<vector<int>> {newInterval};
        vector<vector<int>> res;
        int curInd = 0;
        const int len = intervals.size();

        while (curInd < len && intervals[curInd][1] < newInterval[0])
            res.push_back(intervals[curInd++]);
        
        int start = (curInd < len && intervals[curInd][0] < newInterval[0]) ? \
            intervals[curInd][0] : newInterval[0];
        int end = -1;
        if (newInterval[0] == newInterval[1])
            end = newInterval[1];
        
        while (curInd < len && intervals[curInd][1] < newInterval[1])
            ++curInd;
        
        if (curInd < len && (
            intervals[curInd][1] == newInterval[1] || // 等於
            intervals[curInd][0] < newInterval[1] || // 介於
            intervals[curInd][0] == newInterval[1]))  // 鄰接
            end = intervals[curInd++][1];
        else // 小於, 例外
            end = newInterval[1];
        
        res.push_back({start, end});
        while (curInd < len)
            res.push_back(intervals[curInd++]);
        return res;
    }
};
// @lc code=end

