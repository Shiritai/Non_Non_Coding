/**
 * Created by Eroiko at 2021/07/21
 */
package Java;
import java.util.Arrays;

public class Weight_for_weight {
    
    public static int valueOfString(String a){
        int cnt = 0;
        var a_ = a.toCharArray();
        for (int i = 0, size = a.length(); i < size; ++i){
            if (a_[i] < '0' || a_[i] > '9'){
                throw new IllegalArgumentException("Bad number string : [" + a + "]");
            }
            cnt += a_[i] - '0';
        }
        return cnt;
    }
    
    public static String orderWeight(String string) {
        var list = string.trim().split("\\s+");
		Arrays.sort(list, (a, b) -> {
            int a_val = valueOfString(a);
            int b_val = valueOfString(b);
            return (a_val != b_val) ? a_val - b_val : a.compareTo(b);
        });
        return String.join(" ", list);
	}

    public static void main(String [] args){
        // System.out.println(orderWeight("2000 103 123 4444 99")); // sorted
        System.out.println(orderWeight("103 123 4444 99 2000")); // sorted
    }
}
