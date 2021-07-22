/**
 * Created by Eroiko at 2021/07/22
 */
package Java;
import java.util.ArrayList;
import java.util.List;
import java.util.ArrayDeque;

public class Sort_binary_tree_by_levels {

    static class Node {
        public Node left;
        public Node right;
        public int value;
        
        public Node(Node l, Node r, int v) {
            left = l;
            right = r;
            value = v;
        }
    }
    
    public static List<Integer> treeByLevels(Node node){
        if (node == null){ return List.of(); }
        var queue = new ArrayDeque<Node>();
        queue.add(node);
        var res = new ArrayList<Integer>();
        while (!queue.isEmpty()){
            var tmp = queue.poll();
            res.add(tmp.value);
            if (tmp.left != null){
                queue.add(tmp.left);
            }
            if (tmp.right != null){
                queue.add(tmp.right);
            }
        }
        return res;
    }

}
