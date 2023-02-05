/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int thresh, ret = 0;
        // 左閉右開
        vector<pair<int, int>> st 
            { pair<int, int>(0, heights.size()) };
        
        while (!st.empty()) {
            pair<int, int> pr = st.back();
            st.pop_back();
            auto from = heights.begin() + pr.first,
                   to = heights.begin() + pr.second;
            thresh = *min_element(from, to); // bottleneck
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

    /** 
     * Accept: Runtime 74.05% (well)
     *         Memory 92.57% (very nice)
     */
    int maximalRectangle(vector<vector<char>>& matrix) {
        const int row = matrix.size(), col = matrix.front().size();
        int ret = 0, from;

        // version 1: brute force
        // auto fetch_height = [&](vector<char> & of) -> int { 
        //         int _ret = 0; 
        //         for (; _ret + from < col; ++_ret) 
        //             if (of[_ret + from] != '1') 
        //                 break; 
        //         return _ret;
        //     };
        
        // for (from = 0; from < col; ++from) {
        //     vector<int> heights;
        //     heights.reserve(col);
        //     transform(matrix.begin(), matrix.end(),
        //               inserter(heights, heights.begin()), 
        //               fetch_height);
        //     ret = max(ret, largestRectangleArea(heights));
        // }

        // version 2: DP
        vector<int> heights(col, 0);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) 
                heights[j] = (matrix[i][j] == '1') ? 
                    heights[j] + 1 : 0;
            ret = max(ret, largestRectangleArea(heights));
        }

        return ret;
    }
};
// @lc code=end

