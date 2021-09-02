/*
 * @lc app=leetcode id=859 lang=c
 *
 * [859] Buddy Strings
 */

// @lc code=start
/* 
 * Authored by Eroiko at 2021/09/01
 * Time : beats 34.7 %
 * Space : beats 100 %
 */
# include <string.h>
bool buddyStrings(char * s, char * goal){
    int len = strlen(s), _len = strlen(goal);
    if (len != _len)
        return false;
    char diff1_1 = '\0', diff1_2 = '\0', diff2_1, diff2_2;
    int map[26];
    for (int i = 0; i < 26; map[i++] = 0);
    for (int i = 0; i < len; ++i){
        if (s[i] != goal[i]){
            if (diff1_1 == '\0')
                diff1_1 = s[i], diff2_1 = goal[i];
            else if (diff1_2 == '\0')
                diff1_2 = s[i], diff2_2 = goal[i];
            else 
                return false;
        }
        else 
            ++map[s[i] - 'a'];
    }
    if (diff1_1 == '\0'){
        for (int i = 0; i < 26; ++i)
            if (map[i] > 1)
                return true;
        return false;
    }
    return diff1_1 == diff2_2 && diff1_2 == diff2_1;
}
// @lc code=end

