package Java;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;

/*
 * @lc app=leetcode id=212 lang=java
 *
 * [212] Word Search II
 */

// @lc code=start

/* 
 * Authored by Eroiko at 2021/07/26
 * Time : beats 5 %
 * Space : beats 35.6 %
 */

class Trie {
    protected class Node {
        protected boolean isWord;
        protected HashMap<Character, Node> next;

        public Node traverse(char ch){ return next.get(ch); }

        public Node(boolean isWord){
            this.isWord = isWord;
            next = new HashMap<>();
        }
        
        public Node(){ this(false); }
    }

    private Node root;

    public Trie(){
        root = new Node();
    }

    public void add(String s){
        Node cur = root;
        for (var ch : s.toCharArray()){
            Node tmp;
            if ((tmp = cur.next.get(ch)) == null){
                cur.next.put(ch, (tmp = new Node()));
            }
            cur = tmp;
        }
        if (!cur.isWord){
            cur.isWord = true;
        }
    }

    public Node traverseFromRoot(){ return root; }
}

class Board {
    char [][] board;
    int vLength, hLength;

    /**
     * Create a board traverser, assume the board is a square
     * @param board
     * @param shallowCopy
     */
    public Board(char [][] board, boolean shallowCopy){
        if (board.length == 0){
            throw new IllegalArgumentException("No element!");
        }
        vLength = board.length;
        hLength = board[0].length;
        
        if (shallowCopy){
            this.board = board;
        }
        else {
            this.board = new char [vLength][hLength];
            for (int i = 0; i < vLength; ++i){
                for (int j = 0; j < hLength; ++j){
                    this.board[i][j] = board[i][j];
                }
            }
        }
    }

    public boolean insideBoard(int v, int h){
        return v >= 0 && v < vLength && h >= 0 && h < hLength;
    }

    public char at(int v, int h){
        if (insideBoard(v, h)){
            return board[v][h];
        }
        throw new IllegalArgumentException("Board index out of range!");
    }

    public char atWithNoCheck(int v, int h){ return board[v][h]; }

    public Walker getWalker(int v, int h){
        return new Walker(this, v, h);
    }
}

class Walker {
    static class Coo {
        int v, h;
        Coo(int v, int h){ this.v = v; this.h = h; }
        @Override
        public boolean equals(Object that){
            if (that instanceof Coo){
                var coo = (Coo) that;
                return coo.v == v && coo.h == h;
            }
            return false;
        }
    }
    
    int vInd, hInd;
    Board box;
    ArrayList<Coo> list;

    public Walker(Board box, int vInd, int hInd){
        this.box = box;
        this.vInd = vInd;
        this.hInd = hInd;
        this.list = new ArrayList<>();
        this.list.add(new Coo(vInd, hInd));
    }

    public Walker(Board box, int vInd, int hInd, ArrayList<Coo> list){
        this.box = box;
        this.vInd = vInd;
        this.hInd = hInd;
        this.list = new ArrayList<>(list);
        this.list.add(new Coo(vInd, hInd));
    }

    public List<Walker> move(char target){
        var res = new ArrayList<Walker>(4);
        if (!hasWalked(vInd, hInd - 1) &&
            box.insideBoard(vInd, hInd - 1) && 
            box.atWithNoCheck(vInd, hInd - 1) == target){
            res.add(new Walker(box, vInd, hInd - 1, list));
        }
        if (!hasWalked(vInd, hInd + 1) &&
            box.insideBoard(vInd, hInd + 1) && 
            box.atWithNoCheck(vInd, hInd + 1) == target){
            res.add(new Walker(box, vInd, hInd + 1, list));
        }
        if (!hasWalked(vInd - 1, hInd) &&
        box.insideBoard(vInd - 1, hInd) && 
        box.atWithNoCheck(vInd - 1, hInd) == target){
            res.add(new Walker(box, vInd - 1, hInd, list));
        }
        if (!hasWalked(vInd + 1, hInd) &&
            box.insideBoard(vInd + 1, hInd) && 
            box.atWithNoCheck(vInd + 1, hInd) == target){
            res.add(new Walker(box, vInd + 1, hInd, list));
        }
        return res;
    }

    public boolean hasWalked(int v, int h){ return list.contains(new Coo(v, h)); }

    @Override
    public String toString(){
        var tmp = new StringBuilder(list.size());
        list.forEach(l -> tmp.append(box.at(l.v, l.h)));
        return tmp.toString();
    }
}

class Solution {
    public List<String> findWords(char [][] board, String [] words) {
        var trie = new Trie();
        for (var w : words){ trie.add(w); }

        var res = new HashSet<String>();
        var bd = new Board(board, true);
        
        int vLen = board.length, hLen = board[0].length;
        for (int i = 0; i < vLen; ++i){
            for (int j = 0; j < hLen; ++j){
                char ch = board[i][j];
                var node = trie.traverseFromRoot().traverse(ch);
                if (node == null){ continue; }
                walkBoard(res, node, bd.getWalker(i, j));
            }
        }
        return new ArrayList<>(res);
    }

    public void walkBoard(HashSet<String> res, Trie.Node from, Walker walker){
        if (from.isWord){
            res.add(walker.toString());
        }
        from.next.entrySet().forEach(e -> {
            var walkers = walker.move(e.getKey());
            for (var w : walkers){
                walkBoard(res, e.getValue(), w);
            }
        });
    }
}
// @lc code=end

