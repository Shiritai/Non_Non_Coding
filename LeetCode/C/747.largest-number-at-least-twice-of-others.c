/*
 * @lc app=leetcode id=747 lang=c
 *
 * [747] Largest Number At Least Twice of Others
 */

// @lc code=start
/* 
 * Authored by Eroiko at 2021/09/02
 * Time : beats 14.6 %
 * Space : beats 96.3 %
 */
int dominantIndex(int * nums, int numsSize){
    int max[2] = {-1, -1}, sec[2] = {-1, -1};
    for (int i = 0; i < numsSize; ++i){
        if (nums[i] > max[0]){
            sec[0] = max[0];
            sec[1] = max[1];
            max[0] = nums[i];
            max[1] = i;
        }
        else if (nums[i] > sec[0]){
            sec[0] = nums[i];
            sec[1] = i;
        }
    }
    if (sec[0] == -1 || nums[max[1]] >= (nums[sec[1]] << 1))
        return max[1];
    return -1;
}
// @lc code=end

