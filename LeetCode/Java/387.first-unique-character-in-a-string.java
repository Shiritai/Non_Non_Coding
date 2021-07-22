/*
 * @lc app=leetcode id=387 lang=java
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution {
    public int firstUniqChar(String s) {
        var freq = new int[26];
        for (var ch : s.toCharArray()){
            ++freq[ch - 'a'];
        }
        for (int i = 0; i < s.length(); ++i){
            if (freq[s.charAt(i) - 'a'] == 1){
                return i;
            }
        }
        return -1;
    }
}
// @lc code=end

