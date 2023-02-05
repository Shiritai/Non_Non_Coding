/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int master, l = 0, r = matrix.size(), mid, strict;
        // step1: fetch master index
        do {
            strict = r - l;
            int cache;
            if (target == (cache = matrix[(mid = ((l + r) >> 1))][0]))
                break;
            else if (target < cache) 
                r = mid;
            else 
                l = mid;
        } while (strict != r - l);
        master = mid;
        // step2: fetch the target
        l = 0;
        r = matrix[master].size();
        do {
            strict = r - l;
            int cache;
            if (target == (cache = matrix[master][(mid = ((l + r) >> 1))])) 
                return true;
            else if (target < cache) 
                r = mid;
            else 
                l = mid;
        } while (strict != r - l);
        return false;
    }
};
// @lc code=end

