/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string destination, string pattern) {
        int d_ind = 0, p_ind = 0, d_len = destination.length(), p_len = pattern.length();
        int * ls = get_failure_list(pattern);
        for (int i = 0; i < p_len; ++i)
            cout << ls[i] << ' ';
        cout << endl;
        while (p_ind < p_len && d_ind < d_len){ // 邊界條件
            cout << "d_ind: " << d_ind << ", p_ind: " << p_ind << endl;
            if (destination[d_ind] == pattern[p_ind]) // 匹配一個 char
                ++d_ind, ++p_ind; // 因此移動索引繼續比較
            else { // 匹配失敗
                if (!p_ind) // 先前從未匹配 pattern 的任一 char
                    ++d_ind; // 因此 destination 直接向右移
                else 
                    p_ind = ls[p_ind - 1] + 1; // 藉由 failure function 提升效率
            }
        }
        delete [] ls;
        cout << "d_ind: " << d_ind << endl;
        cout << "d_len: " << d_len << endl;
        cout << "p_ind: " << p_ind << endl;
        cout << "p_len: " << p_len << endl;
        return p_ind >= p_len ? d_ind - p_len : -1;
    }

    /* After using the returned list, the user must delete it personally */
    int * get_failure_list(string str){
        int len = str.length();
        if (!len)
            return NULL;
        int * list = new int[len];
        list[0] = -1;
        /* Fill the DP table, i.e. failure list */
        for (int i = 1; i < len; ++i){
            if (str[i] == str[0])
                list[i] = 0;
            else if (list[i - 1] != -1 && str[i] == str[list[i - 1] + 1]) // 接續前面的相同字串
                list[i] = list[i - 1] + 1;
            else // 都沒有相符的
                list[i] = -1;
        }
        return list;
    }
};

int main(void) {
    string des = "aabaaabaaac";
    string pat = "aabaaac";
    auto p = (new Solution)->strStr(des, pat);
    cout << p << endl;
}
// @lc code=end

