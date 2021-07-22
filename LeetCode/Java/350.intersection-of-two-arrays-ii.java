/*
 * @lc app=leetcode id=350 lang=java
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
import java.util.TreeMap;
import java.util.ArrayList;
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        var map = new TreeMap<Integer, Integer>();
        for (var i : nums1){
            if (map.containsKey(i))
                map.put(i, map.get(i) + 1);
            else
                map.put(i, 1);
        }
        var arr = new ArrayList<Integer>();
        for (var i : nums2){
            if (map.containsKey(i)){
                arr.add(i);
                map.put(i, map.get(i) - 1);
                if (map.get(i) == 0)
                    map.remove(i);
            }
        }
        int [] tmp = new int[arr.size()];
        for (int i = 0; i < arr.size(); ++i)
            tmp[i] = arr.get(i);
        return tmp;
    }
}
// @lc code=end

