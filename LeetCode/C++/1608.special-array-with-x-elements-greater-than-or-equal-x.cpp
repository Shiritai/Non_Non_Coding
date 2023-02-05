/*
 * @lc app=leetcode id=1608 lang=cpp
 *
 * [1608] Special Array With X Elements Greater Than or Equal X
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    /** 
    * Accept: runtime 100%
    *          memory 12.28%
    */
    int specialArray(vector<int>& arr) {
        const size_t sz = arr.size();           // O(1)
        vector<int> bucket(sz + 1, 0);          // O(1)
        for (auto n: arr)                       // O(n)
            ++bucket[n >= sz ? sz : n];             // O(1)
        vector<int> cum(sz + 1, 0);             // O(1)
        cum[sz] = bucket[sz];                   // O(1)
        for (int i = sz - 1; i >= 0; --i)          // O(n)
            cum[i] = bucket[i] + cum[i + 1];    // O(1)
        for (int i = sz; i >= 0; --i)           // at most O(n)
            if (i == cum[i])                        // is special number
                return cum[i];                  // O(1)
        return -1;
    }
};
// @lc code=end

