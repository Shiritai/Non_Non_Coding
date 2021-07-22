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
    private class Freq{
        int e, freq;

        public Freq(int e, int freq){
            this.e = e;
            this.freq = freq;
        }
    }

    /* 比較器!!! */
    public class FreqComparator implements Comparator<Freq>{
        @Override
        public int compare(Freq a, Freq b){
            return a.freq - b.freq;
        }
    }
    
    public int[] topKFrequent(int[] nums, int k) {
        var map = new TreeMap<Integer, Integer>();
        for (var i : nums){
            if (map.containsKey(i))
                map.put(i, map.get(i) + 1);
            else
                map.put(i, 1);
        }

        var queue = new PriorityQueue<Freq>(new FreqComparator()); // 希望頻率低者越優先 (被 dequeue 掉)
        /* O(n*log(k)) */
        for (var key : map.keySet()){
            if (queue.size() < k){
                queue.add(new Freq(key, map.get(key)));
            }
            else if (map.get(key) > queue.peek().freq){
                queue.remove();
                queue.add(new Freq(key, map.get(key)));
            }
        }
        var result = new int [k]; 
        for (int i = 0; i < k; ++i)
            result[i] = queue.poll().e; // poll : doesn't throw exception if the queue is empty!
        return result;
    }
}
// @lc code=end

