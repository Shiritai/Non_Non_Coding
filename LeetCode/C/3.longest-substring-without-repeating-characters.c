/*
 * @lc app=leetcode id=3 lang=c
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
/* 
 * Authored by Eroiko at 2021/07/22
 * Space : beats 96 %
 * Time : beats 83 %
 */
inline int max(int a, int b){ return a > b ? a : b; }

int lengthOfLongestSubstring(char * s){
    int map[128] = {0}, start = 0, end = -1, res = 0;
    while (s[++end] != '\0'){
        if (map[s[end]] || (end && s[end] == s[0])){
            res = max(res, end - start);
            start = max(map[s[end]] + 1, start);
        }
        map[s[end]] = end;
    }
    return max(res, end - start);
}
// @lc code=end

