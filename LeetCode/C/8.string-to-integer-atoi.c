/*
 * @lc app=leetcode id=8 lang=c
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
/* 
 * Authored by Eroiko at 2021/07/22
 * Time : beats 100 %
 * Space : beats 65.6 %
 */
# include <stdio.h>
int myAtoi(char * s){
    int res = 0, sign = 0; // sign == 0 : positive
    while (* s == ' ') ++s;
    switch (* s){
    case '+': ++s; break;
    case '-': ++s; sign = 1; break;
    default : break;
    }
    for (; * s >= '0' && * s <= '9'; ++s){
        long long tmp = res * 10ll + (* s - '0');
        if (tmp > 0x7fffffff)
            return sign ? 0x80000000 : 0x7fffffff;
        else 
            res = tmp;
    }
    return (sign ? -1 : 1) * res;
}
// @lc code=end

