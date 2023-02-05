/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    /** 
     * TLE (47/48): descending order
     */
    int candy(vector<int>& ratings) {
        int val = 0, // current value to add
            last_r = -1, // last rate
            last_dec,
            res = 0; // numbers of candy
        vector<int> to_add;
        const int len = ratings.size();
        to_add.reserve(len);
        for (int i = 0, r; i < len; ++i) {
            r = ratings[i];
            if (r > last_r) {
                ++val;
                last_dec = i;
                to_add.push_back(val);
            }
            else if (r == last_r) {
                val = 1;
                last_dec = i;
                to_add.push_back(val);
            }
            else {
                val = 1;
                to_add.push_back(0);
                int _i = i;
                bool stair_form;

                do {
                    stair_form = to_add[_i - 1] <= to_add[_i] + 1;
                } while (last_dec < --_i && stair_form);

                int cache = i - _i - !stair_form;
                while (cache--)
                    ++to_add[i - cache - 1];
                ++to_add.back();
            }

            last_r = r;
        }
        for (auto &n: to_add)
            res += n;
        return res;
    }
};
// @lc code=end

