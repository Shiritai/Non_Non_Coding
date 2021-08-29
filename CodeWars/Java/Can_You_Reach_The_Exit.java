package Java;

import java.util.HashSet;

public class Can_You_Reach_The_Exit {
    static class Coo {
        Integer x, y;
        Coo(int x, int y){
            this.x = x;
            this.y = y;
        }
        @Override
        public boolean equals(Object obj) {
            var other = (Coo) obj;
            return x == other.x && y == other.y;
        }
        /* 
         * should make sure that the same Coo 
         * should have the same hash code!
         */
        @Override
        public int hashCode() {
            return this.x.hashCode() + this.y.hashCode();
        }
    }
    static boolean pathFinder(String maze) {
        var cooSet = new HashSet<Coo>();
        /* walk starts from the very corner */
        int len = (int) Math.sqrt(maze.length());
        System.out.println(len);
        return walk(len - 1, len - 1, len, maze, cooSet);
    }
    /**
     * walk from current Coo recursively (DFS)
     */
    static boolean walk(int x, int y, int bound, String maze, HashSet<Coo> coos){
        if (x == 0 && y == 0) return true;
        var coo = new Coo(x, y);
        if (!coos.contains(coo) && x >= 0 && x < bound && y >= 0 && y < bound && maze.charAt((bound + 1) * y + x) != 'W'){
            coos.add(coo);
            if (walk(x - 1, y, bound, maze, coos)) return true;
            if (walk(x + 1, y, bound, maze, coos)) return true;
            if (walk(x, y - 1, bound, maze, coos)) return true;
            if (walk(x, y + 1, bound, maze, coos)) return true;
        }
        return false;
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
        System.out.println(pathFinder(a));
        System.out.println(pathFinder(b));
        System.out.println(pathFinder(c));
        System.out.println(pathFinder(d));
    }
}
