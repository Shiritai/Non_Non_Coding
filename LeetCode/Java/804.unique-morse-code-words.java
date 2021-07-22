/*
 * @lc app=leetcode id=804 lang=java
 *
 * [804] Unique Morse Code Words
 */

// @lc code=start
import java.util.TreeSet; // 紅黑樹 (完全二叉樹的一種)
class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String[] code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        var data = new TreeSet<String>();
        for (var i : words){
            var tmp = new StringBuilder();
            for (var j : i.toCharArray()){
                tmp.append(code[j - 'a']);
            }
            data.add(tmp.toString());
        }
        return data.size();
    }
}
// @lc code=end

