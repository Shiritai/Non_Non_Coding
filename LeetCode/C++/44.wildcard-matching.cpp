/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        const int s_len = s.size() + 1, p_len = p.size() + 1;
        vector<vector<bool>> table(s_len, vector<bool>(p_len, false));

        s = ' ' + s;
        p = ' ' + p;
        table[0][0] = true;
        for (int i = 1; i < p_len; ++i) {
            if (p[i] != '*')
                break;
            table[0][i] = true;
        }
        
        for (int i = 1; i < s_len; ++i) {
            const char & sc = s[i];
            for (int j = 1; j < p_len; ++j) {
                const char & pc = p[j];
                if (pc == '*') 
                    table[i][j] = table[i][j-1] || table[i-1][j];
                else if (pc == '?' || pc == sc)
                    table[i][j] = table[i-1][j-1];
            }
        }

        return table[s_len-1][p_len-1];
    }
};
// @lc code=end

