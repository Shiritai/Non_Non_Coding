package Java;

import java.util.TreeMap;

public class Next_smaller_number_with_the_same_digits {

    /**
     * A.k.a last permutation :)
     * @param n
     * @return
     */
    public static long nextSmaller(long n){
        var n_arr = String.valueOf(n).toCharArray();
        var numMap = new TreeMap<Character, Integer>(); // <數字字符, 索引>
        for (int i = n_arr.length - 1; i >= 1; --i){
            if (!numMap.containsKey(n_arr[i])){
                numMap.put(n_arr[i], i);
            }
            if (n_arr[i] < n_arr[i - 1]){
                var entry = numMap.lowerEntry(n_arr[i - 1]);
                char tmp = n_arr[i - 1];
                n_arr[i - 1] = entry.getKey();
                n_arr[entry.getValue()] = tmp;
                for (int j = i; j < (n_arr.length + i) / 2; ++j){
                    char tp = n_arr[j];
                    n_arr[j] = n_arr[n_arr.length - j + i - 1];
                    n_arr[n_arr.length - j + i - 1] = tp;
                }
                return n_arr[0] != '0' ? Long.parseLong(String.valueOf(n_arr)) : -1;
            }
        }
        return -1;
    }

    public static void main(String [] args){
        System.out.println(nextSmaller(131247));
        System.out.println(nextSmaller(131227));
        System.out.println(nextSmaller(131347));
        System.out.println(nextSmaller(1027));
        System.out.println(nextSmaller(111));
        System.out.println(nextSmaller(135));
        System.out.println(nextSmaller(5));
        System.out.println(nextSmaller(217));
        System.out.println(nextSmaller(2071));
        System.out.println(nextSmaller(21));
        System.out.println(nextSmaller(531));
    }
}