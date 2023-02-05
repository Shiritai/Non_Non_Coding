/*
 * @lc app=leetcode id=47 lang=rust
 *
 * [47] Permutations II
 */

// @lc code=start
// impl Solution {
//     pub fn permute_unique(nums: Vec<i32>) -> Vec<Vec<i32>> {
//         nums.sort();
//         println!("{}", nums);
//     }
// }

fn next_permutation(mut nums: & Vec<i32>) -> bool {
    let mut i = nums.len() - 2;
    // while i >= 1 {
    //     if &nums[i - 1] < &nums[i] {

    //     }
    // }
    
    // for i in (0..(nums.len() - 1)).rev() {
    //     print!("{}", &nums[i]);
    // }
    true
}

fn permute_unique(nums: Vec<i32>) /*-> Vec<Vec<i32>>*/ {
    let len = nums.len();
    let ret: Vec<Vec<i32>> = Vec::new();
    let mut tmp = Vec::with_capacity(len);
    if len == 0 || len == 1 {
        ret.append(& mut tmp);
        // return ret;
    }
    tmp.copy_from_slice(&nums[..]);
    tmp.sort();
    next_permutation(& mut tmp);
    // println!("{:?}", tmp);
    
}

fn main(){
    permute_unique(vec![3, 2, 1]);
}

// @lc code=end

