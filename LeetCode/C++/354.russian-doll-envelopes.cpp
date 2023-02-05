/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

// @lc code=start
#include <bitset>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <utility>

using namespace std;

struct HWPair {
public:
    int h, w;
    HWPair(int h, int w): h(h), w(w) {};
    HWPair(): HWPair(0, 0) {};
    bool operator==(const HWPair & other) const {
        return h == other.h && w == other.w;
    }
};

namespace std {
    template <>
    struct hash<HWPair> {
        std::size_t operator()(const HWPair& p) const {
            return hash<int>()(p.h) ^ hash<int>()(p.w);
        }
    };
}

class Solution {
public:

    int maxEnvelopes(vector<vector<int>>& env) {
        // int col = 0, row = 0;
        // unordered_set<HWPair> st;

        // support implementation 3
        // set<int> widths;
        // set<int> heights;

        /** 
         * Implementation 0: speed up the module
         * 
         * Achieve to 84/87 (TLE)
         */
        // transform(env.begin(), env.end(),
        //           inserter(widths, widths.begin()),
        //           [] (auto & v) -> int { return v[0]; });
        // transform(env.begin(), env.end(),
        //           inserter(heights, heights.begin()),
        //           [] (auto & v) -> int { return v[1]; });
        
        // before Implementation 5: old version
        // for (auto &v: env) {
        //     st.insert(HWPair(v[1], v[0]));

        //     // support implementation 3
        //     widths.insert(v[0]);
        //     heights.insert(v[1]);
            
        //     col = max(v[0], col);
        //     row = max(v[1], row);
        // }
        // ++col, ++row;

        
        // cout << col << ", " << row << ", size: " << st.size() << endl;

        /** 
         * Implementation 1: Basic DP
         * 
         * Achieve to 79/87 (TLE)
         */
        // vector<vector<int>> table(row, vector<int>(col, 0));
        //
        // for (int i = 1; i < row; ++i) 
        //     for (int j = 1; j < col; ++j) 
        //         table[i][j] = 
        //             max(max(table[i - 1][j], 
        //                     table[i][j - 1]), 
        //                 table[i - 1][j - 1] + 
        //                 (st.find(HWPair(i, j)) != st.end()));
        //
        // return table[row - 1][col - 1];
        
        /** 
         * Implementation 2: DP with better space usage
         * 
         * Achieve to 79/87 (TLE)
         */
        // vector<vector<int>> table(2, vector<int>(col, 0));

        // for (int i = 1; i < row; ++i) 
        //     for (int j = 1; j < col; ++j) 
        //         table[i & 1][j] = 
        //             max(max(table[(i - 1) & 1][j], 
        //                     table[i & 1][j - 1]), 
        //                 table[(i - 1) & 1][j - 1] + 
        //                 (st.find(HWPair(i, j)) != st.end()));

        // return table[(row - 1) & 1][col - 1];

        /** 
         * Implementation 3: DP with skipping function
         *
         * Achieve to 80/87 (TLE)
         */
        // vector<int> width_vec(widths.begin(), widths.end());
        // vector<int> height_vec(heights.begin(), heights.end());
        // vector<vector<int>> table(row, vector<int>(col, 0));

        // const int start_i = height_vec.front(),
        //           start_j = width_vec.front();
        // int last_i = start_i - 1, i_offset;
        // for (auto& i: height_vec) {
        //     i_offset = i - last_i;
        //     last_i = i;
        //     int last_j = start_j - 1, j_offset;
        //     for (auto& j: width_vec) {
        //         j_offset = j - last_j;
        //         last_j = j;
        //         table[i][j] = 
        //             max(max(table[i - i_offset][j], 
        //                     table[i][j - j_offset]), 
        //                 table[i - i_offset][j - j_offset] + 
        //                     (st.find(HWPair(i, j)) != st.end()));
        //     }
        // }
        // return table[row - 1][col - 1];

        /** 
         * Implementation 4: DP with skipping function 
         * and space trimming.
         * 
         * Achieve to 83/87 (TLE)
         * Achieve to 84/87 (TLE) (with implementation 0)
         */
        // const int c_col = widths.size()+ 1,  // compressed
        //           c_row = heights.size()+ 1; // compressed
        // vector<vector<int>> table(c_row, vector<int>(c_col, 0));
        // {
        //     unordered_map<int, int> hmp, wmp;
        //     int i = 1;
        //     transform(heights.begin(), heights.end(),
        //               inserter(hmp, hmp.begin()),
        //               [&] (auto & h) { return pair<int, int>(h, i++); });
        //     i = 1;
        //     transform(widths.begin(), widths.end(),
        //               inserter(wmp, wmp.begin()),
        //               [&] (auto & w) { return pair<int, int>(w, i++); });
        //     // int i = 1;
        //     // for (auto & h: heights)
        //     //     hmp[h] = i++;
        //     // i = 1;
        //     // for (auto & w: widths)
        //     //     wmp[w] = i++;
        //     for (auto & v: env) 
        //         table[hmp[v[1]]][wmp[v[0]]] = 1;
        // }

        // for (int i = 1; i < c_row; ++i) 
        //     for (int j = 1; j < c_col; ++j) 
        //         table[i][j] = 
        //             max(max(table[i-1][j],
        //                     table[i][j-1]), 
        //                 table[i-1][j-1] + table[i][j]);
                        
        // return table[c_row-1][c_col-1];
        
        /** 
         * Implementation 5: DP version 2
         * 
         * Achieve to 85/87 (TLE)
         */
        // sort(env.begin(), env.end());
        // const size_t len = env.size();
        // vector<int> table(len, 1);
        // for (int i = 0; i < len; ++i) 
        //     for (int j = 0; j < i; ++j)
        //         if (env[i][0] > env[j][0] && env[i][1] > env[j][1])
        //             table[i] = max(table[i], table[j] + 1);
        // return *max_element(table.rbegin(), table.rend());

        /** 
         * Implementation 5-1: DP version 2 with cmp opt
         * 
         * Achieve to 85/87 (TLE) (same as before)
         */
        // sort(env.begin(), env.end(), 
        //     [](auto& v1, auto& v2) -> bool 
        //         { return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] > v2[1]); });
        // const size_t len = env.size();
        // vector<int> table(len, 1);
        // for (int i = 0; i < len; ++i) 
        //     for (int j = 0; j < i; ++j)
        //         if (env[i][1] > env[j][1])
        //             table[i] = max(table[i], table[j] + 1);
        // return *max_element(table.rbegin(), table.rend());

        /** 
         * Implementation 6: Longest increasing subsequence
         * 
         * All passed, runtime 93.26%, memory 92.5%
         */
        sort(env.begin(), env.end(), 
            [](auto& v1, auto& v2) -> bool 
                { return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] > v2[1]); });
        vector<int> lis;
        for (auto &v: env) {
            if (lis.empty() || v[1] > lis.back())
                lis.push_back(v[1]);
            else 
                *lower_bound(lis.begin(), lis.end(), v[1]) = v[1];
        }
        return lis.size();

        
        // return -1;
    }
};
// @lc code=end

