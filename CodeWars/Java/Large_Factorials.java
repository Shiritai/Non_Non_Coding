/**
 * Created by Eroiko at 2021/07/21
 */
package Java;
import java.util.ArrayList;

public class Large_Factorials {

    public static String Factorial(int n) {
        var bigNum = new ArrayList<Integer>();
        bigNum.add(1);
        for (int i = n; i > 1; --i){
            int size = bigNum.size();
            for (int e = 0; e < size; ++e){
                bigNum.set(e, bigNum.get(e) * i);
            }
            int pos = 0;
            do {
                int d;
                if ((d = bigNum.get(pos)) > 9){
                    bigNum.set(pos, d % 10);
                    if (pos + 1 == bigNum.size()){
                        bigNum.add(d / 10);
                    }
                    else {
                        bigNum.set(pos + 1, bigNum.get(pos + 1) + d / 10);
                    }
                }
            } while (++pos != bigNum.size());
        }
        var res = new StringBuilder();
        bigNum.forEach(res::append);
        return res.reverse().toString();
    }

    public static void main(String [] args){
        System.out.println(Factorial(10));
    }
}