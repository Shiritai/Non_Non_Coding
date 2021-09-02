/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
/* 
 * Authored by Eroiko at 2021/08/31
 * Time : beats 100 %
 * Space : beats 91.8 %
 */
// # include <string>
// # include <stdarg.h>
// using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length() + 1, len2 = word2.length() + 1;
        int table[len1][len2];
        /* init */
        for (int i = 0; i < len1; ++i)
            table[i][0] = i;
        for (int i = 1; i < len2; ++i)
            table[0][i] = i;
        /* fill table */
        for (int i = 1; i < len1; ++i){
            for (int j = 1; j < len2; ++j){
                if (word1[i - 1] == word2[j - 1])
                    table[i][j] = table[i - 1][j - 1];
                else {
                    /* 配合練習 OwO */
                    // table[i][j] = min(
                    //     3, 
                    //     table[i - 1][j] + 1, 
                    //     table[i][j - 1] + 1,
                    //     table[i - 1][j - 1] + 1
                    // );
                    int min_v = table[i - 1][j] + 1;
                    if (min_v > table[i][j - 1] + 1)
                        min_v = table[i][j - 1] + 1;
                    if (min_v > table[i - 1][j - 1] + 1)
                        min_v = table[i - 1][j - 1] + 1;

                    table[i][j] = min_v;
                }
            }
        }
        return table[len1 - 1][len2 - 1];
    }
private: 
    /* 練習一下多參數的使用 */
    int min(int numberOfParameter, ...){
        va_list ap;
        va_start(ap, numberOfParameter); // 準備開始提取參數, 確認有幾個參數
        int min_val = 0x7fffffff;
        while (numberOfParameter--){
            int tmp = va_arg(ap, int);  // 取出參數, 並指定其型別
            if (tmp < min_val)
                min_val = tmp;
        }
        va_end(ap); // 結束提取參數
        return min_val;
    }
};
// @lc code=end

