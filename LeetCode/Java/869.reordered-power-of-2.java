import java.util.Arrays;

/*
 * @lc app=leetcode id=869 lang=java
 *
 * [869] Reordered Power of 2
 */

// @lc code=start
/* 
 * Authored by Eroiko at 2021/08/28
 * Time : beats 36.7 %
 * Space : beats 13.2 %
 */
class TwosPower {
    private int value;
    private String val_str;
    private boolean change;
    TwosPower(){
        value = 1;
        val_str = "1";
        change = false;
    }
    @Override
    public String toString() {
        if (change){
            change = false;
            return val_str = String.valueOf(value);
        }
        return val_str;
    }
    public TwosPower grow(){
        value <<= 1;
        change = true;
        return this;
    }
}

class Solution {
    
    public boolean reorderedPowerOf2(int n) {
        if (n <= 0){ return false; }

        var target = String.valueOf(n);

        if (!(target.contains("1") || target.contains("2") ||
            target.contains("4") || target.contains("6") || target.contains("8"))){
            return false;
        }

        var map = new int [10];
        for (int i = 0; i < 10; ++i){ map[i] = 0; }
        for (int i = 0, len = target.length(); i < len; ++i){
            ++map[target.charAt(i) - '0'];
        }

        var cur = new TwosPower();
        while (cur.toString().length() != target.length()){
            cur.grow();
        }

        while (cur.toString().length() == target.length()){
            var mapCopied = Arrays.copyOf(map, map.length);
            var tmp_str = cur.toString();
            boolean ok = true;

            for (int i = 0, len = tmp_str.length(); i < len && ok; ++i){
                --mapCopied[tmp_str.charAt(i) - '0'];
                if (mapCopied[tmp_str.charAt(i) - '0'] < 0){
                    ok = false;
                }
            }

            for (int i = 0; i < 10 && ok; ++i){
                if (mapCopied[i] != 0){
                    ok = false;
                }
            }

            if (ok){
                return true;
            }

            cur.grow();
        }
        return false;
    }
}
// @lc code=end

