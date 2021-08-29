/*
 * @lc app=leetcode id=69 lang=c
 *
 * [69] Sqrt(x)
 */

// @lc code=start

/* 
 * Authored by Eroiko at 2021/07/26
 * Time : beats 6.4 %
 * Space : beats 36.9 %
 */

int mySqrt(int x){
    long long i = 2, tmp;
    while ((tmp = i * i) != x && 
        !(tmp < x && (i + 1) * (i + 1) > x)){
        i = (tmp > x) ? ((x * x < tmp) ? x : i - 1) : ((tmp * tmp < x) ? tmp : i + 1);
    }
    return i;
}
// @lc code=end

