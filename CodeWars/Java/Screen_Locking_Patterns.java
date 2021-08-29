

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;

class Edge {
    public final int another;
    public final boolean isAvailable;
    public Edge(int another, boolean isAvailable){
        this.another = another;
        this.isAvailable = isAvailable;
    }
}

class Point {
    private ArrayList<Edge> connected;
    public Point(int edgeCapacity){
        this.connected = new ArrayList<>(edgeCapacity);
    }
    public void addEdge(Edge e){ connected.add(e); }
    public Iterator<Edge> iterator(){ return connected.iterator(); }
}

class UnorderedPair {
    public int x, y;
    public UnorderedPair(int x, int y){
        this.x = x;
        this.y = y;
    }
    @Override
    public boolean equals(Object obj) {
        var other = (UnorderedPair) obj;
        return x == other.x ? y == other.y :
                x == other.y && y == other.x;
    }
    @Override
    public int hashCode() {
        return Integer.valueOf(x + y).hashCode();
    }
}

class DenseGraph {
    private Point [] graph;
    private int v, e;

    public DenseGraph(int vertex){
        this.v = vertex;
        graph = new Point [v];
        for (int i = 0; i < v; ++i){
            graph[i] = new Point(v);
        }
    }

    public int V(){ return v; }
    public int E(){ return e; }

    public void addEdge(int one, int another, boolean isAvailable){
        graph[one].addEdge(new Edge(another, isAvailable));
    }

    public Iterator<Edge> iterator(int from){
        return graph[from].iterator();
    }

    /**
     * Connect all points with edges.
     * Default edge is available.
     */
    public void connectAll(Set<UnorderedPair> notAvailable){
        for (int i = 0; i < v; ++i){
            for (int j = 0; j < v; ++j){
                if (j != i){
                    graph[i].addEdge(
                        new Edge(
                            j, 
                            !notAvailable.contains(
                                new UnorderedPair(i, j)
                            )
                        )
                    );
                }
            }
        }
    }
}

class LockingTable {
    private DenseGraph g;
    private HashMap<UnorderedPair, Integer> notAvailable;

    public LockingTable(){
        g = new DenseGraph(9);
        notAvailable = new HashMap<UnorderedPair, Integer>();
        connectAll();
    }

    private void connectAll(){
        notAvailable.put(new UnorderedPair(0, 2), 1);
        notAvailable.put(new UnorderedPair(3, 5), 4);
        notAvailable.put(new UnorderedPair(6, 8), 7);
        notAvailable.put(new UnorderedPair(0, 6), 3);
        notAvailable.put(new UnorderedPair(1, 7), 4);
        notAvailable.put(new UnorderedPair(2, 8), 5);
        notAvailable.put(new UnorderedPair(0, 8), 4);
        notAvailable.put(new UnorderedPair(2, 6), 4);
        g.connectAll(notAvailable.keySet());
    }

    private int count;
    private boolean [] unused;
    private boolean [] covered;

    public int walkAndCount(int from, int length){
        if (length == 0 || length > 9){ return 0; }
        if (length == 1){ return 1; }
        count = 0;
        unused = new boolean [9];
        covered = new boolean [9];
        for (int i = 0; i < 9; ++i){
            unused[i] = true;
            covered[i] = false;
        }
        g.iterator(from).forEachRemaining(p -> walk(from, p, length - 1));
        return count;
    }

    private void walk(int from, Edge current, int remainLength){
        if (unused[current.another] && (
            current.isAvailable || covered[current.another]
        )){
            if (remainLength == 1){
                ++count;
                return;
            }
            
            unused[current.another] = false;
            var becomeAvailable = notAvailable.get(new UnorderedPair(from, current.another));
            if (becomeAvailable != null){
                covered[becomeAvailable] = true;
            }
            
            g.iterator(current.another).forEachRemaining(p -> walk(from, p, remainLength - 1));
            
            unused[current.another] = true;
            if (becomeAvailable != null){
                covered[becomeAvailable] = false;
            }
        }
    }
}

public class Screen_Locking_Patterns {
    
    static LockingTable tb = null;
    
    public static int calculateCombinations(char startPosition, int patternLength){
        if (tb == null){
            tb = new LockingTable();
        }
        return tb.walkAndCount(startPosition - 'A', patternLength);
    }

    public static void main(String [] args){
        System.out.println(calculateCombinations('A', 1));
        System.out.println(calculateCombinations('B', 1));
        System.out.println(calculateCombinations('C', 2));
        System.out.println(calculateCombinations('E', 2));
        System.out.println(calculateCombinations('E', 3));
        System.out.println(calculateCombinations('E', 4));
        System.out.println(calculateCombinations('A', 14));
    }
}

/* 
I think that `("E", 4)` should returns `264` rather than `256`, below is how I calculate manually:

Let's say there are two types of nodes : `inner` (B, D, F, H) and `outer` (A, C, G, I)

Since we have 4 steps, our permutation of nodes must be :
```
E -> inner (4) -> inner (3) -> __ (6)
E -> inner (4) -> outer (4) -> __ (5)
E -> outer (4) -> inner (4) -> __ (6)
E -> outer (4) -> outer (1) -> __ (4)
```
where `__` means the remained nodes and the number in bracket means the possible number of node

By rule of product and rules of sum, the total number of ways is 264.

Is there something wrong about the count method above or something? 
*/