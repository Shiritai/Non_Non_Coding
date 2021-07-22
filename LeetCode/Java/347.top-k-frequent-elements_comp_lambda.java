/*
 * @lc app=leetcode id=347 lang=java
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
import java.util.TreeMap;
import java.util.PriorityQueue;
import java.util.Comparator;
class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        var map = new TreeMap<Integer, Integer>();
        for (var i : nums){
            if (map.containsKey(i))
            map.put(i, map.get(i) + 1);
            else
            map.put(i, 1);
        }
        /* Lambda 比較器 */
        var queue = new PriorityQueue<Integer>(
            (a, b) -> map.get(a) - map.get(b)
        ); // 希望頻率低者越優先 (被 dequeue 掉)
        /* O(n*log(k)) */
        for (var key : map.keySet()){
            if (queue.size() < k){
                queue.add(key);
            }
            else if (map.get(key) > map.get(queue.peek())){
                queue.remove();
                queue.add(key);
            }
        }
        var result = new int [k]; 
        for (int i = 0; i < k; ++i)
            result[i] = queue.poll(); // poll : doesn't throw exception if the queue is empty!
        return result;
    }
}
// @lc code=end