/*
 * @lc app=leetcode id=13 lang=rust
 *
 * [13] Roman to Integer
 */

// @lc code=start
/* 
 * Time: 100% (0ms)
 * Space: 60.7% (2.1MB)
 */
fn roman_to_int(s: String) -> i32 {
    let val_of_chr = |c: char| {
        match c {
            'I' => 1,
            'V' => 5,
            'X' => 10,
            'L' => 50,
            'C' => 100,
            'D' => 500,
            'M' => 1000,
            _ => 0,
        }
    };
    let mut ret = 0;
    let mut last = 0;
    for c in s.chars().rev() {
        let tmp = val_of_chr(c);
        match ret == 0 || last <= tmp {
            true => ret += tmp,
            false => ret -= tmp,
        }
        last = tmp;
    }
    ret
}

fn main(){
    println!("{}", roman_to_int(String::from("III")));
    println!("{}", roman_to_int(String::from("IV")));
    println!("{}", roman_to_int(String::from("IX")));
    println!("{}", roman_to_int(String::from("LVIII")));
    println!("{}", roman_to_int(String::from("MCMXCIV")));
}

// @lc code=end

