/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        const size_t sz = height.size();

        int ret = 0, cache = 0;
        int from = 0, h;
        while (from + 1 < sz && (h = height[from]) < height[from + 1]) ++from;
        // cout << (height[from] ? string(height[from], '>') : "") << endl;
        for (int i = from + 1; i < sz; ++i) {
            if (height[i] >= h) {
                ret += cache;
                cache = 0;
                from = i;
                h = height[i];
                // cout << (height[i] ? string(height[i], '>') : "") << endl;
            }
            else {
                cache += h - height[i];
                // cout << (height[i] ? string(height[i], '>') : "") 
                //      << ((h - height[i]) ? string(h - height[i], '*') : "") << endl;
            }
        }
        
        // process the tailing elements
        int to = sz - 1;
        cache = 0;
        while (to && (h = height[to]) <= height[to - 1]) --to;
        // cout << "to: " << to << endl;
        // cout << (height[to] ? string(height[to], '>') : "") << endl;
        for (int i = to - 1; i >= from; --i) {
            if (height[i] >= h) {
                ret += cache;
                cache = 0;
                h = height[i];
                // cout << (height[i] ? string(height[i], '>') : "") << endl;
            }
            else {
                cache += h - height[i];
                // cout << (height[i] ? string(height[i], '>') : "") 
                //      << ((h - height[i]) ? string(h - height[i], '*') : "") << endl;
            }
        }

        return ret;
    }
};
// @lc code=end

