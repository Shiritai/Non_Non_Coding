/*
 * @lc app=leetcode id=9 lang=rust
 *
 * [9] Palindrome Number
 */

// @lc code=start
impl Solution {
    /*
    * Time : 100.00%, 0ms
    * Space : 27.87%, 2.2MB
    */
    pub fn is_palindrome(x: i32) -> bool {
        if x < 0 {
            return false;
        }
        let mut it = 1;
        let mut v: Vec<i32> = Vec::new();
        while x / it >= 10 {
            it *= 10;
        }
        let mut x_ = x;
        while it > 0 {
            v.push(x_ / it);
            x_ %= it;
            it /= 10;
        }
        for i in 0..(v.len() >> 1) {
            if &v[i] != &v[v.len() - i - 1]{
                return false;
            }
        }
        true
    }
}
// fn main(){
//     println!("{}", is_palindrome(121)); // t
//     println!("{}", is_palindrome(1)); // t
//     println!("{}", is_palindrome(10)); // f
//     println!("{}", is_palindrome(1213)); // f
//     println!("{}", is_palindrome(1234)); // f
//     println!("{}", is_palindrome(11)); // t
//     println!("{}", is_palindrome(1111111)); // t
//     println!("{}", is_palindrome(111111)); // t
//     println!("{}", is_palindrome(1000_000_001)); // t
// }
// @lc code=end