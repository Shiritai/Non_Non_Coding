/*
 * @lc app=leetcode id=916 lang=cpp
 *
 * [916] Word Subsets
 */

// @lc code=start
/* 
 * Authored by Eroiko at 2021/08/28
 * Time : beats 82.7 %
 * Space : beats 87 %
 */
# include <vector>
# include <string>
using namespace std;
# define LETTER_LEN 26
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        int map[LETTER_LEN];
        for (int i = 0; i < LETTER_LEN; ++i)
            map[i] = 0;
        for (auto & s: words2){
            int map_tmp[LETTER_LEN];
            for (int i = 0; i < LETTER_LEN; ++i)
                map_tmp[i] = 0;
            for (auto c : s)
                ++map_tmp[c - 'a'];
            for (int i = 0; i < LETTER_LEN; ++i)
                map[i] = (map[i] < map_tmp[i]) ? map_tmp[i] : map[i];
        }
        for (auto & s : words1){
            int map_cp[LETTER_LEN];
            for (int i = 0; i < LETTER_LEN; ++i)
                map_cp[i] = map[i];
            for (auto c : s)
                --map_cp[c - 'a'];
            bool ok = true;
            for (int i = 0; i < LETTER_LEN && ok; ++i)
                if (map_cp[i] > 0)
                    ok = false;
            if (ok)
                res.push_back(s);
        }
        return res;
    }
};
// @lc code=end

