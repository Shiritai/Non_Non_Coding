/**
 * Created by Eroiko at 2021/07/21
 */
package Java;
public class Simple_Pig_Latin {
    public static String pigIt(String str) {
        var list = str.toCharArray();
        char ch = '\0';
        var ret = new StringBuilder();
        for (var c : list){
            if (ch == '\0' && Character.isAlphabetic(c)){
                ch = c;
            }
            else if (ch != '\0' && !Character.isAlphabetic(c)){
                ret.append(ch).append("ay").append(c);
                ch = '\0';
            }
            else {
                ret.append(c);
            }
        }
        if (ch != '\0'){
            ret.append(ch).append("ay");
        }
        return ret.toString();
    }

    public static void main(String [] args){
        System.out.println(pigIt("Pig latin is cool"));
    }

    /**
     * Regex 大師解法
     * public static String pigIt(String str) {
     *     return str.replaceAll("(\\w)(\\w*)", "$2$1ay");
     * }
     */
}
