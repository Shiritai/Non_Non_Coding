/*
 * @lc app=leetcode id=349 lang=java
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
import java.util.TreeSet;
import java.util.ArrayList;
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        // var data = new TreeSet<Integer>();
        // var result = new TreeSet<Integer>();
        // for (var i : nums1)
        //     data.add(i);
        // for (var i : nums2){
        //     if (data.contains(i)){
        //         result.add(i);
        //         data.remove(i);
        //     }
        // }
        // Integer [] resultArr = new Integer[result.size()];
        // resultArr = result.toArray(resultArr);
        // return IntegerToInt(resultArr);
        
        var data = new TreeSet<Integer>();
        var result = new ArrayList<Integer>();
        for (var i : nums1)
            data.add(i);
        for (var i : nums2){
            if (data.contains(i)){
                result.add(i);
                data.remove(i);
            }
        }
        var resultArr = new int[result.size()];
        for (int i = 0; i < result.size(); ++i)
            resultArr[i] = result.get(i);
        return resultArr;
    }
    // public static int [] IntegerToInt(Integer [] tmp){
    //     var result = new int [tmp.length];
    //     for (int i = 0; i < tmp.length; ++i)
    //         result[i] = tmp[i];
    //     return result;
    // }
}
// @lc code=end

