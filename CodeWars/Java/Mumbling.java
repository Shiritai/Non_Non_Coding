/**
 * Created by Eroiko at 2021/07/21
 */
package Java;
public class Mumbling {
    public static String accum(String s) {
        var list = s.toCharArray();
        var res = new StringBuilder((list.length * (list.length + 1)) >> 1 + list.length); // init with the exact space 
        for (int i = 0; i < list.length; ++i){
            res.append(Character.toUpperCase(list[i]));
            var ch = Character.toLowerCase(list[i]);
            for (int j = 0; j < i; ++j, res.append(ch));
            res.append('-');
        }
        res.deleteCharAt(res.length() - 1);
        return res.toString();
    }
}
