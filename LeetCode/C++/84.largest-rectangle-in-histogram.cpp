/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    /** 
     * Accepted: runtime: 5.05% (very slow)
     *           memory: 99.76% (very slender)
     */
    int largestRectangleArea(vector<int>& heights) {
        int thresh, ret = 0;
        // 左閉右開
        vector<pair<int, int>> st 
            { pair<int, int>(0, heights.size()) };
        
        while (!st.empty()) {
            pair<int, int> pr = st.back();
            auto from = heights.begin() + pr.first,
                   to = heights.begin() + pr.second;
            thresh = *min_element(from, to); // bottleneck
            st.pop_back();
            int _cur_val = thresh * (pr.second - pr.first);
            ret = max(ret, _cur_val);
            int cur = pr.first;
            for (int i = pr.first; i < pr.second; ++i) {
                if (heights[i] == thresh) {
                    if (cur != i)
                        st.push_back(pair<int, int>(cur, i));
                    cur = i + 1;
                }
            }
            if (cur < pr.second)
                st.push_back(pair<int, int>(cur, pr.second));
        }
        return ret;
    }
};
// @lc code=end

