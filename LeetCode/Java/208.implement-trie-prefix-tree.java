/*
 * @lc app=leetcode id=208 lang=java
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
import java.util.TreeMap;

class Trie {
    private class Node {
        public TreeMap<Character, Node> next;
        public boolean isWord;
        Node(boolean isWord){
            next = new TreeMap<>();
            this.isWord = isWord;
        }
        Node(){
            this(false);
        }
    } 

    private Node root;

    /** Initialize your data structure here. */
    public Trie() {
        root = new Node();
    }

    private static final int INSERT = 0;
    private static final int SEARCH = 1;
    private static final int START_WITH = 2;
    
    private boolean dive(String word, int mode){
        Node cur = root;
        for (Character i : word.toCharArray()){
            if (cur.next.get(i) == null){
                switch (mode){
                    case Trie.INSERT : cur.next.put(i, new Node()); break;
                    case Trie.SEARCH, Trie.START_WITH : return false;
                    default : System.out.println("Error occur!"); break;
                }
            }
            cur = cur.next.get(i);
        }
        switch (mode){
            case Trie.INSERT : cur.isWord = true;
            case Trie.SEARCH : return cur.isWord;
            case Trie.START_WITH : return true;
            default : return false;
        }
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        dive(word, Trie.INSERT);
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        return dive(word, Trie.SEARCH);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        return dive(prefix, Trie.START_WITH);
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
// @lc code=end

