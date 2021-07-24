import java.util.ArrayList;
import java.util.Stack;
import java.util.function.Function;

public class Tmp {
    /* Definition of expression tree's node */
    private static class Node {
        /* Helper class, just like pair in C++ */
        static class myPair<K, V> {
            public K key;
            public V value;
            public myPair(K key, V value){
                this.key = key;
                this.value = value;
            }
        }
    
        /** 
         * Helper class, which defines node's element, containing a pure function.
         * It's ok to merge this class with the class "Node"
         */
        static class Element {
            public static final Element ADD = new Element(t -> t.key.calculate() + t.value.calculate());
            public static final Element SUB = new Element(t -> t.key.calculate() - t.value.calculate());
            public static final Element MUL = new Element(t -> t.key.calculate() * t.value.calculate());
            public static final Element DIV = new Element(t -> t.key.calculate() / t.value.calculate());
            
            public final Function<myPair<Node, Node>, Integer> op;
    
            public Element(Function<myPair<Node, Node>, Integer> op){ this.op = op; }
        }
        
        /* Definition */
        public Element element;
        public Node left, right;
        public Node(String e){
            switch (e){
                case "+" : this.element = Element.ADD; break;
                case "-" : this.element = Element.SUB; break;
                case "*" : this.element = Element.MUL; break;
                case "/" : this.element = Element.DIV; break;
                default :
                    var num = Integer.parseInt(e);
                    this.element = new Element(t -> num);
                    break;
            };
            left = right = null;
        }
        public Integer calculate(){ // left <op> right
            var tmp = element.op.apply(new myPair<Node, Node>(left, right));
            System.out.println(tmp);
            return tmp;
            // return element.op.apply(new myPair<Node, Node>(left, right));
        }
    }

    /* Helper function to get the rank of an element string */
    private static int myRank(String str){
        int res = 0;
        switch (str){
            case "+" : res = 1; break;
            case "-" : res = 1; break;
            case "*" : res = 2; break;
            case "/" : res = 2; break;
            default : break;
        };
        return res;
    }

    private static ArrayList<String> parse(String expression){
        var res = new ArrayList<String>();
        var builder = new StringBuilder();
        var list = expression.replaceAll(" ", "").toCharArray();
        for (int i = 0; i < list.length; ++i){
            if (i >= list.length){ break; }
            if (Character.isDigit(list[i])){
                builder = new StringBuilder();
                while (true){
                    builder.append(list[i]);
                    if (i + 1 < list.length && Character.isDigit(list[i + 1])){
                        ++i;
                    }
                    else {
                        break;
                    }
                }
                res.add(builder.toString());
            }
            else if (list[i] == '+'){ res.add("+"); }
            else if (list[i] == '-'){
                var checkFront = (i == 0 || (!res.get(res.size() - 1).equals(")") && !Character.isDigit(res.get(res.size() - 1).charAt(0))));
                if (checkFront && list[i + 1] == '('){
                    res.add("0");
                    res.add("-");
                }
                else if (checkFront && Character.isDigit(list[i + 1])){
                    builder = new StringBuilder();
                    builder.append('-');
                    do {
                        builder.append(list[++i]);
                    } while (i + 1 < list.length && Character.isDigit(list[i + 1]));
                    res.add(builder.toString());
                }
                else { res.add("-"); }
            }
            else { res.add(Character.toString(list[i])); } // parentheses
        }
        System.out.println("--------------");
        res.forEach(System.out::println);
        System.out.println("--------------");
        return res;
    }
    
    /* Use stack to evaluate a expression to a postfix order stack */
    private static Stack<String> postfixNotation(String expression){
        var list = parse(expression);
        var stack = new Stack<String>();
        var postfix = new Stack<String>();
        for (var l : list){
            int rank = myRank(l);
            if (l.equals("(")){
                stack.add(l);
            }
            else if (!stack.isEmpty() && l.equals(")")){
                while (!stack.peek().equals("(")){
                    postfix.add(stack.pop());
                }
                stack.pop(); // pop "("
            }
            else if (rank == 0){
                postfix.add(l);
            }
            else {
                if (!stack.isEmpty() && rank <= myRank(stack.peek())){ // need pop
                    do {
                        postfix.add(stack.pop());
                    } while (!stack.isEmpty() && rank <= myRank(stack.peek()));
                }
                stack.add(l);
            }
        }
        while (!stack.isEmpty()){ postfix.add(stack.pop()); }
        System.out.println("-----------");
        postfix.forEach(System.out::println);
        System.out.println("-----------");
        return postfix;
    }

    /* Recursively build a expression tree */
    private static Node build(Stack<String> list){
        if (list.isEmpty()){ return null; }
        var e = list.pop();
        Node cur = new Node(e);
        if (myRank(e) != 0){ // is operand
            cur.right = build(list);
            cur.left = build(list);
        }
        return cur;
    }
    
    public static int calculate(String s) {
        return build(postfixNotation(s)).calculate();
    }
    
    public static void main(String [] args){
        System.out.println(calculate("(7)-(0)+(4)"));
        // System.out.println(calculate("1-(5)"));
    }
}
