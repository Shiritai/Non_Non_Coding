/*
 * @lc app=leetcode id=303 lang=java
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
class NumArray {
    private int [] sum; // sum[i] 存前 i 個元素的合, sum[0] = 0, 長 i + 1

    public NumArray(int[] nums) {
        sum = new int [nums.length + 1];
        for (int i = 0; i < nums.length; ++i){
            sum[i + 1] = nums[i] + sum[i];
        }
    }
    
    public int sumRange(int left, int right) {
        return sum[right + 1] - sum[left];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(left,right);
 */
// @lc code=end

