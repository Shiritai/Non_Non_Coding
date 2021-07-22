/*
 * @lc app=leetcode id=211 lang=java
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start
import java.util.TreeMap;

class WordDictionary {

    private class Node {
        private boolean isWord;
        private TreeMap<Character, Node> next;
        
        Node(boolean isWord){
            this.isWord = isWord;
            next = new TreeMap<>();
        }

        Node(){
            this(false);
        }
    }

    private Node root;

    /** Initialize your data structure here. */
    public WordDictionary() {
        root = new Node();
    }
    
    public void addWord(String word) {
        Node cur = root;
        for (Character chr : word.toCharArray()) {
            if (cur.next.get(chr) == null){
                cur.next.put(chr, new Node());
            }
            cur = cur.next.get(chr);
        }
        cur.isWord = true;
    }
    
    public boolean search(String word) {
        return match(root, word, 0);
    }

    private boolean match(Node cur, String word, int wordPos){
        if (cur == null){
            return false;
        }
        if (wordPos == word.length()){
            return cur.isWord;
        }
        char c = word.charAt(wordPos);
        if (c != '.'){
            return match(cur.next.get(c), word, wordPos + 1);
        }
        else {
            for (Character chr : cur.next.keySet()){
                if (match(cur.next.get(chr), word, wordPos + 1)) {
                    return true;
                }
            }
            return false;
        }
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */
// @lc code=end

