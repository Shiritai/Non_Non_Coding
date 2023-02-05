/*
 * @lc app=leetcode id=1537 lang=cpp
 *
 * [1537] Get the Maximum Score
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    /** 
     * Accept: runtime 80.52%
     *          memory 87.41%
     */
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        long long res = 0, acc_i = 0, acc_j = 0;
        size_t i = 0, j = 0;
        const size_t i_lim = nums1.size(), 
                     j_lim = nums2.size();

        while (i < i_lim && j < j_lim) {
            int ni = nums1[i], nj = nums2[j];
            if (ni == nj) {
                res += ni + max(acc_i, acc_j);
                acc_i = acc_j = 0;
                ++i, ++j;
            }
            else if (ni < nj) {
                acc_i += ni;
                ++i;
            }
            else {
                acc_j += nj;
                ++j;
            }
        }
        while (i < i_lim)
            acc_i += nums1[i++]; 
        while (j < j_lim)
            acc_j += nums2[j++]; 
        res += max(acc_i, acc_j);
        
        return (int) (res % 1000000007);
    }
};
// @lc code=end

