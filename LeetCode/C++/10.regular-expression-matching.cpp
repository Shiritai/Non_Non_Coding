/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
/* 
 * Authored by Eroiko at 2021/09/02
 * Time : beats 100 %
 * Space : beats 81.4 %
 */
# include <string>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length() + 1, pLen = p.length() + 1;
        bool table[sLen][pLen];
        for (int i = 0; i < sLen; ++i) // init
            for (int j = 0; j < pLen; ++j)
                table[i][j] = false;
        
        table[0][0] = true;
        for (int i = 1; i < pLen; ++i) // 考慮 a*b*c* 這些可匹配 "" 的情況
            if (p[i - 1] == '*')
                table[0][i] = table[0][i - 2];
        
        for (int i = 1; i < sLen; ++i){
            for (int j = 1; j < pLen; ++j){
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
                    table[i][j] = table[i - 1][j - 1];
                else if (p[j - 1] == '*')
                    table[i][j] = table[i][j - 2] || \
                        ((s[i - 1] == p[j - 2] || p[j - 2] == '.') && table[i - 1][j]);
                else 
                    table[i][j] = false;
            }
        }
        return table[sLen - 1][pLen - 1];
    }
};
// @lc code=end

