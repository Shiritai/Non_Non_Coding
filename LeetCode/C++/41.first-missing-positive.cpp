/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
#include <vector>
#include <unordered_set>
#include <set>
#include <map>
#include <utility>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ret = 1;
        unordered_set<int> st(nums.begin(), nums.end());
        for (; st.find(ret) != st.end(); ++ret);
        return ret;
    }
};
// @lc code=end

// int tmp() {
//     map<int, int> m;
//     m[1] = 1;
//     m.insert(pair<int, int>(1, 1));

//     set<int> s;
//     s.insert(1);
//     for (auto _s: s) {}
//     for (auto it = s.begin(); it != s.end(); ++it) { *it; }
//     if (s.find(1) != s.end()) {}
    
//     s.lower_bound(1);
//     s.upper_bound(10);
// }

