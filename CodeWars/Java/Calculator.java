/**
 * Created by Eroiko at 2021/07/22
 */
package Java;
import java.util.Stack;
import java.util.function.Function;

public class Calculator {

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
            
            public final Function<myPair<Node, Node>, Double> op;
    
            public Element(Function<myPair<Node, Node>, Double> op){ this.op = op; }
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
                    var num = Double.parseDouble(e);
                    this.element = new Element(t -> num);
                    break;
            };
            left = right = null;
        }
        public Double calculate(){ // left <op> right
            return element.op.apply(new myPair<Node, Node>(left, right));
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

    public static Double evaluate(String expression){
        return build(postfixNotation(expression)).calculate();
    }
    
    /* Use stack to evaluate a expression to a postfix order stack */
    private static Stack<String> postfixNotation(String expression){
        var list = expression.split(" ");
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
    
    public static void main(String [] args){
        System.out.println(evaluate("2 / 2 + ( 3 * 4 ) - 6"));
    }

    /**
     * If "(" and ")" doesn't included... below is one  of the clever solutions!
     * 
     * public static Double evaluate(String expression) {
     *     String[] parts = expression.split(" ");
     *     Stack<Double> s = new Stack<>();
     *     for (int i = 0; i < parts.length; i += 2) { // iterate with step = 2
     *         if (i == 0 || parts[i - 1].equals("+")) {
     *             s.push(Double.valueOf(parts[i]));
     *         } else if (parts[i - 1].equals("-")) {
     *             s.push(-Double.valueOf(parts[i]));
     *         } else if (parts[i - 1].equals("*")) {
     *             s.push(s.pop() * Double.valueOf(parts[i]));
     *         } else if (parts[i-1].equals("/")) {
     *             s.push(s.pop() / Double.valueOf(parts[i]));
     *         }
     *     }
     *     double r = 0.0;
     *     while(!s.isEmpty()) {
     *       r += s.pop();
     *     }
     *     return r;
     * }
     */
}
