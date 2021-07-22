/**
 * Created by Eroiko at 2021/07/21
 */
package Java;
import java.util.ArrayList;
import java.util.LinkedList;

public class Pyramid_Slide_Down {

    static class Node {
        int maxSum;
        LinkedList<Integer> list; // 本題不需要蒐集路徑的值, 可去掉增加性能
        public Node(int maxSum, LinkedList<Integer> list){
            this.maxSum = maxSum;
            this.list = list;
        }
    }

    public static Node superNodeGenerator(Node l, Node r, int currentValue){
        Node survivor = (l.maxSum > r.maxSum) ? l : r;
        var renewedList = new LinkedList<Integer>();
        survivor.list.forEach(renewedList::add);
        renewedList.add(currentValue);
        return new Node(survivor.maxSum + currentValue, renewedList);
    }
    
    public static int longestSlideDown(int[][] pyramid) {
        /* 將最底層打包成節點 ArrayList<Node> */
        int floorPos = pyramid.length - 1;
        var levelList = new ArrayList<Node>(pyramid[floorPos].length);
        for (int i = 0; i < pyramid[floorPos].length; ++i){
            var tmpList = new LinkedList<Integer>();
            tmpList.add(pyramid[floorPos][i]);
            levelList.add(new Node(pyramid[floorPos][i], tmpList));
        }
        /* 自倒數第二底層向上遍歷, 生成新節點 ArrayList, 並移除下層節點 ArrayList */
        for (int i = pyramid.length - 2; i >= 0; --i){
            /* 自左向右遍歷, 生成並蒐集新節點 */
            int len = pyramid[i].length;
            var newList = new ArrayList<Node>(len);
            for (int j = 0; j < len; ++j){
                newList.add(superNodeGenerator(levelList.get(j), levelList.get(j + 1), pyramid[i][j]));
            }
            levelList = newList;
        }
        levelList.get(0).list.forEach(System.out::println); // 列印最大值路徑
        return levelList.get(0).maxSum;
    }
}
