/*
 * @lc app=leetcode id=30 lang=java
 *
 * [30] Substring with Concatenation of All Words
 */

import java.util.List;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.ArrayList;
import java.util.HashMap;
// import java.util.Map;
// import java.util.AbstractMap;
// import java.util.Stack;


// @lc code=start
class Trie {
    // 26 ways search tree
    class Node {
        /** 
         * reference of children nodes
         */
        public Node[] child;
        
        /** 
         * Size of child node
         */
        public int childSize;

        /** 
         * is this node represent a leaf node (a complete word)
         */
        public boolean isLeaf;

        public Node() { child = new Node[26]; childSize = 0; isLeaf = false; }
    }

    /** 
     * Root of Trie
     */
    private Node root;
    
    /** 
     * Number of words of Trie
     */
    private int sz;
    
    public Trie() { root = new Node(); sz = 0; }

    public int size() { return sz; }

    /** 
     * Add a word to this trie
     */
    public void add(String word) {
        Node cur = root;
        for (var c: word.toCharArray()) {
            if (cur.child[c] == null) {
                cur.child[c] = new Node();
                ++cur.childSize;
            }
            cur = cur.child[c];
        }
        if (!cur.isLeaf) {
            cur.isLeaf = true;
            ++sz;
        }
    }
    
    /** 
     * Check if this trie contains a word
     */
    public boolean contains(String word) {
        Node cur = root;
        for (var c: word.toCharArray()) {
            if (cur.child[c] == null) {
                return false;
            }
            else {
                cur = cur.child[c];
            }
        }
        
        return cur.isLeaf;
    }
    
    public boolean isPrefix(String word) {
        Node cur = root;
        for (var c: word.toCharArray()) {
            if (cur.child[c] == null) {
                return false;
            }
            else {
                cur = cur.child[c];
            }
        }
        
        return true;
    }
    
    // public boolean delete(String word) {
    //     var st = new Stack<Map.Entry<Character, Node>>();
    //     Node cur = root;
    //     for (var c: word.toCharArray()) {
    //         if (cur.child[c] == null) { // not exist
    //             return false;
    //         }
    //         else {
    //             st.add(new AbstractMap.SimpleEntry<>(c, cur));
    //             cur = cur.child[c];
    //         }
    //     }
    //     if (cur.isLeaf) {
    //         do {
    //             var entry = st.pop();
                
                
    //             if (cur.isLeaf) {
    //                 break;
    //             }
    //         } while (!st.isEmpty());
    //         return true;
    //     }
    //     else {
    //         return false;
    //     }
    // }
}

class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        // dictionary object
        var dict = new HashMap<String, Integer>(
            List.of(words)
                .stream()
                .collect(Collectors.toMap(Function.identity(), (_s) -> 0)));
        int dictSize = 0;
                
        // cache word object
        int start = 0, end = 0;
        
        // initialize a trie
        var trie = new Trie();
        for (var _s: words) {
            trie.add(_s);
        }

        boolean got = false;
        for (var c: s.toCharArray()) {
            
        }
        return new ArrayList<>();
    }
}
// @lc code=end

