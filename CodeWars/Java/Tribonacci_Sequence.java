/**
 * Created by Eroiko at 2021/07/21
 */
package Java;
import java.util.LinkedList;

public class Tribonacci_Sequence {
    public double[] tribonacci(double[] s, int n) {
        if (n < s.length){
            var res = new double[n];
            for (int i = 0; i < n; ++i){
                res[i] = s[i];
            }
            return res;
        }
        var queue = new LinkedList<Double>();
        for (var e : s){ queue.addFirst(e); }
        int cnt = n - s.length;
        while (cnt-- > 0){
            double d = 0;
            d += queue.get(0) + queue.get(1) + queue.get(2);
            queue.push(d);
        }
        var res = new double[n];
        for (int i = n - 1; i >= 0; --i){
            res[i] = queue.pop();
        }
        return res;
    }    
    
    public static void main(String [] args){
        for (var e : new Tribonacci_Sequence().tribonacci(new double[]{0, 1, 1}, 10)){
            System.out.println(e);
        }
    }

    /**
     * Good Solution
     * import java.util.Arrays;
     * ...
     * public double[] tribonacci(double[] s, int n) {
     *     double[] tritab = Arrays.copyOf(s, n);
     *     for(int i = 3; i < n; i++){
     *           tritab[i] = tritab[i-1] + tritab[i-2] + tritab[i-3];
     *     }
     *     return tritab;
     * }
     */
}
