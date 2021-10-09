/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
/* 
 * Time : 94.65%, 3ms
 * Space : 89.52%, 8.5MB
 */
# include <vector>
# include <algorithm>
# include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        do {
            ret.push_back(vector<int>(nums));
        } while (next_permutation(nums.begin(), nums.end()));
        // for (auto & i : ret){
        //     for (auto & n : i){
        //         cout << n << ' ';
        //     } 
        //     cout << endl;
        // }
        return ret;
    }
};

// int main(void){
//     Solution s;
//     vector<int> v = {1, 1, 2, 3, 4};
//     s.permuteUnique(v);
// }
// @lc code=end

