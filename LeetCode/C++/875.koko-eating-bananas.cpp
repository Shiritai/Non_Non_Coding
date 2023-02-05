/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int fetchEatingTime(vector<int> piles, int speed) {
        int ret = 0;
        for (auto b: piles) 
            ret += b / speed + (b % speed != 0);
        return ret;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int ret = 0, rem = 0, mx = 0;
        for (auto b: piles) {
            ret += b / h + rem / h;
            rem = rem % h + b % h;
            mx = b > mx ? b : mx;
        }
        ret += rem / h + rem % h != 0; // get best eating time
        // cout << "Best time: " << ret << endl;
        int step = 1, acc_thresh = 0, cache;
        int counter = 0;
        while (h < (cache = fetchEatingTime(piles, ret))) {
            ret += step;
            if (++counter == 16) {
                // cout << "ret: " << ret << ", cache: " << cache << ", acc_thresh: " << acc_thresh << endl;
                counter = 0;
                step <<= 1;
            }
        }
        // cout << "\n";
        // cout << "Current ret: " << ret << endl;
        while (ret && h >= (cache = fetchEatingTime(piles, ret))) --ret;
        if (h < cache || !ret) ++ret;
        return ret;
    }
};
// @lc code=end

// int main(void) {
//     vector<int> v { 1,1,1,999999999 };
//     cout << (new Solution)->minEatingSpeed(v, 10) << endl;
// }

