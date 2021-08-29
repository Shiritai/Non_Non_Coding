package Java.Shortest_Path;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;

class IndexMinHeap<T extends Comparable<T>> {

    private class __ {
        int [] indexList;
        private int [] revList;
    
        __(int capacity){
            indexList = new int [capacity];
            revList = new int [capacity];
            for (int i = 0; i < capacity; ++i){
                revList[i] = 0;
            }
        }

        void swapAndMaintain(int a, int b){
            var tmp = indexList[a];
            indexList[a] = indexList[b];
            indexList[b] = tmp;
            revList[indexList[a]] = a;
            revList[indexList[b]] = b;
        }

        void maintain(int K, int V){
            indexList[K] = V;
            revList[V] = K;
        }

        /**
         * 刪除某一元素 --> 破壞 rev 映射
         */
        void delete(int i){
            revList[indexList[i]] = 0; // 指回 0 表示不存在
        }

        boolean exist(int i){
            return revList[i] != 0;
        }

        /**
         * 給原資料陣列之索引就返回其在 Heap 的索引
         */
        int map(int i){
            return revList[i];
        }
    }

    private T [] arr; // 也可用 ArrayList 實現, 在此講求效能所以只用陣列
    private __ ___;
    private int length;

    /**
     * 對 Heap 裡的第 i 位嘗試 shift up
     */
    private void shiftUp(int i){
        while (i > 1 && arr[___.indexList[i >> 1]].compareTo(arr[___.indexList[i]]) > 0){
            ___.swapAndMaintain(i, i >> 1);
            i >>= 1;
        }
    }
    
    /**
     * 對 Heap 裡的第 i 位嘗試 shift down
     */
    private void shiftDown(int i){
        int nextInd = i << 1;
        while (nextInd <= length){
            if (nextInd + 1 < length &&
                arr[___.indexList[nextInd + 1]].compareTo(
                arr[___.indexList[nextInd]]) < 0){
                ++nextInd;
            }
            if (arr[___.indexList[i]].compareTo(
                arr[___.indexList[nextInd]]) < 0){
                break;
            }
            ___.swapAndMaintain(i, nextInd);
            i = nextInd;
            nextInd <<= 1;
        }
    }

    /**
     * 建立不可變長的 Index Min Heap
     * 要可變長, 內部實現就改成 ArrayList
     * @param capacity
     */
    IndexMinHeap(int capacity){ // 0 為空位
        arr = (T []) new Comparable [capacity + 1];
        arr[0] = null;
        ___ = new __(capacity + 1);
        length = 0;
    }

    /**
     * 若不存在則新增, 存在則更新
     * @param i 資料索引
     * @param e 欲設定之元素
     */
    void set(int i, T e){
        assert i >= 0 && i + 1 <= arr.length : "Index out of bound";
        arr[++i] = e;
        if (___.exist(i)){
            shiftUp(___.map(i));
            shiftDown(___.map(i));
        }
        else {
            ___.maintain(++length, i);
            shiftUp(length);
        }
    }

    int popMinIndex(){
        assert length > 0 : "No element in this index min heap";
        int ret = ___.indexList[1] - 1;
        ___.swapAndMaintain(1, length);
        ___.delete(length--);
        shiftDown(1);
        return ret;
    }

    T pop(){
        return arr[popMinIndex() + 1];
    }

    int size(){ return length; }

    boolean isEmpty(){ return length == 0; }
}

class Coo {
    int x, y;
    Coo (int x, int y){
        this.x = x;
        this.y = y;
    }
    @Override
    public String toString() {
        return "(" + x + ", " + y + ")";
    }
}

interface Graph {
    default int toPoint(int x, int y){
        return x * getSide() + y;
    }
    default Coo toCoo(int point){
        int sd = getSide();
        return new Coo(point / sd, point % sd);
    }
    int getSide();
    int V();
    int E();
    void addEdge(int x1, int y1, int x2, int y2);
    boolean hasEdge(int x1, int y1, int x2, int y2);
    Iterator<Integer> iterator(Coo coo);
}

class UndirectedDenseGraphInSquare implements Graph {

    private boolean [][] graph;
    private int side, e;
    UndirectedDenseGraphInSquare(int side){
        this.side = side;
        this.e = 0;
        var size = side * side;
        graph = new boolean [size][];
        for (int i = 0; i < size; ++i){
            graph[i] = new boolean [size];
        }
    }

    @Override
    public int getSide(){ return side; }

    @Override
    public int V(){ return side * side; }

    @Override
    public int E(){ return e; }

    @Override
    public void addEdge(int x1, int y1, int x2, int y2){
        if (!hasEdge(x1, y1, x2, y2)){
            graph[toPoint(x1, y1)][toPoint(x2, y2)] = true;
            graph[toPoint(x2, y2)][toPoint(x1, y1)] = true;
            ++e;
        }
    }

    @Override
    public boolean hasEdge(int x1, int y1, int x2, int y2){
        assert x1 >= 0 && x1 < side &&
                y1 >= 0 && y1 < side &&
                x2 >= 0 && x2 < side &&
                y1 >= 0 && y1 < side : "Invalid coordinate.";
        return graph[toPoint(x1, y1)][toPoint(x2, y2)];
    }

    class __Itr implements Iterable<Integer> {
        int line, index;
        
        __Itr(int x, int y){
            line = toPoint(x, y);
            index = -1;
        }
        
        @Override
        public Iterator<Integer> iterator() {
            var res = new ArrayList<Integer>();
            while (++index < V()){
                if (graph[line][index]){
                    res.add(index);
                }
            }
            return res.iterator();
        }
        
    }

    @Override
    public Iterator<Integer> iterator(Coo coo){
        return new __Itr(coo.x, coo.y).iterator();
    }
}

class UndirectedSparseGraphInSquare implements Graph {

    private ArrayList<HashSet<Integer>> graph;
    private int side, e;
    UndirectedSparseGraphInSquare(int side){
        this.side = side;
        this.e = 0;
        var size = side * side;
        graph = new ArrayList<>(size);
        for (int i = 0; i < size; ++i){
            graph.add(new HashSet<>());
        }
    }

    @Override
    public int getSide(){ return side; }

    @Override
    public int V(){ return side * side; }

    @Override
    public int E(){ return e; }

    @Override
    public void addEdge(int x1, int y1, int x2, int y2){
        if (!hasEdge(x1, y1, x2, y2)){
            graph.get(toPoint(x1, y1)).add(toPoint(x2, y2));
            graph.get(toPoint(x2, y2)).add(toPoint(x1, y1));
            ++e;
        }
    }

    @Override
    public boolean hasEdge(int x1, int y1, int x2, int y2){
        assert x1 >= 0 && x1 < side &&
                y1 >= 0 && y1 < side &&
                x2 >= 0 && x2 < side &&
                y1 >= 0 && y1 < side : "Invalid coordinate.";
        return graph.get(toPoint(x1, y1)).contains(toPoint(x2, y2));
    }

    class __Itr implements Iterable<Integer> {

        private int line;
        
        __Itr(int x, int y){
            this.line = toPoint(x, y);
        }

        @Override
        public Iterator<Integer> iterator() {
            return graph.get(line).iterator();
        }
    }

    @Override
    public Iterator<Integer> iterator(Coo coo) {
        return new __Itr(coo.x, coo.y).iterator();
    }
}

// class Edge {
//     int a, b, weight;
//     Edge(int a, int b, int weight){
//         this.a = a;
//         this.b = b;
//         this.weight = weight;
//     }
// }

class Dijkstra {
    /* Index Min Heap x Dijkstra Algorithm */
    Graph G;
    int origin;
    int [] distTo;
    // ArrayList<ArrayList<Integer>> path;

    Dijkstra(Graph G, int origin){
        this.G = G;
        this.origin = origin;

        int len = G.V();
        distTo = new int [len];
        // path = new ArrayList<>(len);
        for (int i = 0; i < len; ++i){
            distTo[i] = -1;
            // path.add(new ArrayList<Integer>());
        }
        distTo[origin] = 0;
        // path.get(origin).add(origin);

        var ipq = new IndexMinHeap<Integer>(len);
        ipq.set(origin, distTo[origin]);

        while (!ipq.isEmpty()){
            var cur = ipq.popMinIndex(); // 取出最小距離者 (即確定距離者)
            // System.out.println("Cur : " + cur);
            var nextList = G.iterator(G.toCoo(cur));
            // System.out.println("Current relaxing : (" + G.toCoo(cur).x + ", " + G.toCoo(cur).y + "), has next ? " + nextList.hasNext());
            while (nextList.hasNext()){
                var next = nextList.next();
                // System.out.println(G.toCoo(next));
                // System.out.println("Dist to " + next + " : " + distTo[next]);
                if (distTo[next] == -1 || distTo[next] > distTo[cur] + 1){ // 一次移動的權重必 = 1
                    distTo[next] = distTo[cur] + 1;
                    // System.out.println("new Dist to " + next + " : " + distTo[next]);
                    // path.get(next).add(cur);
                    ipq.set(next, distTo[next]);
                }
            }
        }
    }

    /**
     * 若無法到達返回 -1
     * @param x
     * @param y
     * @return
     */
    public int distantToPoint(int x, int y){
        return distTo[G.toPoint(x, y)];
    }
}

public class Shortest_Path {

    public static int pathFinder(String maze) {
        /* > 20 % 使用稠密圖 */
        maze = maze.replaceAll("\n", "");
        Graph g;
        int len = (int) Math.sqrt(maze.length());
        // System.out.println(maze.chars().filter(v -> v != 'W').count() * 5. / 4);
        if (maze.chars().filter(v -> v != 'W').count() * 5. / 4 > maze.length()){
            g = new UndirectedDenseGraphInSquare(len);
            // System.out.println("Use dense!");
        }
        else {
            g = new UndirectedSparseGraphInSquare(len);
            // System.out.println("Use sparse!");
        }
        for (int i = 0, l = maze.length(); i < l; ++i){
            if (maze.charAt(i) != 'W'){
                // System.out.println(g.toCoo(i));
                /* 加右邊 */
                if ((i % len) < (len - 1) && maze.charAt(i + 1) != 'W'){
                    var coo1 = g.toCoo(i);
                    var coo2 = g.toCoo(i + 1);
                    // System.out.println("-----> [r] " + coo2);
                    g.addEdge(coo1.x, coo1.y, coo2.x, coo2.y);
                }
                /* 加下邊 */
                if (i < l - len && maze.charAt(i + len) != 'W'){
                    var coo1 = g.toCoo(i);
                    var coo2 = g.toCoo(i + len);
                    // System.out.println("-----> [d] " + coo2);
                    g.addEdge(coo1.x, coo1.y, coo2.x, coo2.y);
                }
            }
        }
        return new Dijkstra(g, 0).distantToPoint(len - 1, len - 1);
	}

    public static void main(String [] args){
        String a = ".W.\n"+
                 ".W.\n"+
                 "...",
               
             b = ".W.\n"+
                 ".W.\n"+
                 "W..",
               
             c = "......\n"+
                 "......\n"+
                 "......\n"+
                 "......\n"+
                 "......\n"+
                 "......",
               
             d = "......\n"+
                 "......\n"+
                 "......\n"+
                 "......\n"+
                 ".....W\n"+
                 "....W.";

        System.out.println("Result : " + pathFinder(a));
        System.out.println("Result : " + pathFinder(b));
        System.out.println("Result : " + pathFinder(c));
        System.out.println("Result : " + pathFinder(d));
    }
}