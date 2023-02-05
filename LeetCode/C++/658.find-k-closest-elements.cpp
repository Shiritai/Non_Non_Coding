/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [=] (int a, int b) -> bool { 
            const int determiner = abs(a - x) - abs(b - x);
            return determiner < 0 || (!determiner && a < b); });
        auto start = arr.begin();
        sort(start, start + k);
        start = arr.begin();
        return vector<int>(start, start + k);
    }
};
// @lc code=end

