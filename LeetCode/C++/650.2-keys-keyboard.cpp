/*
 * @lc app=leetcode id=650 lang=cpp
 *
 * [650] 2 Keys Keyboard
 */

// @lc code=start
/* 
 * Authored by Eroiko at 2021/09/02
 * Time : beats 100 %
 * Space : beats 53.9 %
 */
# include <unordered_map>
class Solution {
public:
    int minSteps(int n) {
        std::unordered_map<int, int> dpList;
        dpList[1] = 0;
        return L(n, dpList);
    }
private:
    int L(int n, std::unordered_map<int, int> & dpList){
        auto val_it = dpList.find(n);
        if (val_it == dpList.end()){
            int res = 0x7fffffff, tmpN, tmpL;
            for (int i = 1, len = n >> 1; i <= len; ++i){
                if (!(n % i) && (tmpN = n / i) < res && (tmpL = L(i, dpList)) < res){
                    res = min(res, tmpL + tmpN);
                    dpList[i] = tmpL;
                }
            }
            dpList[n] = res;
            return res;
        }
        else
            return val_it->second;
    }
};
// @lc code=end

