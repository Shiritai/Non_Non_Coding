/*
 * @lc app=leetcode id=677 lang=java
 *
 * [677] Map Sum Pairs
 */

// @lc code=start
import java.util.TreeMap;

class MapSum {

    private class Node {
        public TreeMap<Character, Node> next;
        public int weight;

        Node(int weight) {
            this.weight = weight;
            this.next = new TreeMap<>();
        }
        Node(){
            this(0);
        }
    }
    
    private Node root;
    
    /** Initialize your data structure here. */
    public MapSum() {
        root = new Node();
    }
    
    public void insert(String key, int val) {
        Node cur = root;
        for (Character chr : key.toCharArray()) {
            if (cur.next.get(chr) == null){
                cur.next.put(chr, new Node());
            }
            cur = cur.next.get(chr);
        }
        cur.weight = val;
    }
    
    private int preOrderSum(Node cur){
        int sum = cur.weight;
        for (Node next : cur.next.values()){
            sum += preOrderSum(next);
        }
        return sum;
    }
    
    public int sum(String prefix) {
        Node cur = root;
        for (Character chr : prefix.toCharArray()) {
            if (cur.next.get(chr) == null){
                return 0;
            }
            cur = cur.next.get(chr);
        }
        /* 此時已經遍歷完全部的 prefix, 因此開始加總 */
        return preOrderSum(cur);
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
// @lc code=end

