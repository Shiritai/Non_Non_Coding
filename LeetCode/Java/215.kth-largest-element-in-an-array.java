package Java;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

/*
 * @lc app=leetcode id=215 lang=java
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start

/* 
 * Authored by Eroiko at 2021/07/24
 * Time : beats 19.6 %
 * Space : beats 6.2 %
 * Well a bit consuming
 */
class MinHeap<E extends Comparable<E>> {
    private ArrayList<E> arr;
    private final Comparator<E> comp;
    
    public MinHeap(int size){
        this(0, null);
    }
    
    public MinHeap(){ this(16); }

    public MinHeap(Comparator<E> comparator){ this(16, comparator); }
    
    public MinHeap(int size, Comparator<E> comparator){
        arr = new ArrayList<>(size);
        comp = (comparator != null) ? comparator : new Comparator<E>(){
            @Override
            public int compare(E a, E b){ return a.compareTo(b); }
        };
    }

    /**
     * Create a MimHeap use Heapify method
     * @param arr
     */
    public MinHeap(E [] arr){
        this(arr.length, null);
        for (var a : arr){ this.arr.add(a); }
        for (int i = parent(this.arr.size() - 1); i >= 0; --i){
            shiftDown(i);
        }
    }
    
    /**
     * Create a MimHeap use Heapify method
     * @param arr
     * @param comparator
     */
    public MinHeap(E [] arr, Comparator<E> comparator){
        this(arr.length, comparator);
        for (var a : arr){ this.arr.add(a); }
        for (int i = parent(this.arr.size() - 1); i >= 0; --i){
            shiftDown(i);
        }
    }

    public boolean isEmpty(){ return arr.size() == 0; }

    public int size(){ return arr.size(); }

    /* Helper functions */
    private int parent(int ind){ return (ind - 1) / 2; }
    private int leftChildren(int ind){ return ind * 2 + 1; }
    
    public E peek(){
        if (arr.size() == 0){ throw new IllegalArgumentException("MinHeap is Empty!"); }
        return arr.get(0);
    }

    public void shiftUp(int from){
        int tmp;
        while (from > 0 && comp.compare(arr.get(tmp = parent(from)), arr.get(from)) > 0){
            /* swap and change index of "from" */
            var t = arr.get(from);
            arr.set(from, arr.get(tmp));
            arr.set(tmp, t);
            from = tmp;
        }
    }

    public void shiftDown(int from){
        int tmp;
        while ((tmp = leftChildren(from)) < arr.size()){ // left child exist
            if (tmp + 1 < arr.size() && comp.compare(arr.get(tmp), arr.get(tmp + 1)) > 0){
                ++tmp;
            }
            if (comp.compare(arr.get(from), arr.get(tmp)) < 0){
                break;
            }
            var t = arr.get(from);
            arr.set(from, arr.get(tmp));
            arr.set(tmp, t);
            from = tmp;
        }
    }

    public void add(E element){
        arr.add(element);
        shiftUp(arr.size() - 1);
    }

    public E popMin(){
        var res = peek(); // include boundary check
        arr.set(0, arr.get(arr.size() - 1));
        arr.remove(arr.size() - 1);
        shiftDown(0);
        return res;
    }
    
    public E popMinAndReplace(E e){
        var res = peek(); // include boundary check
        arr.set(0, e);
        shiftDown(0);
        return res;
    }
}

class Solution {
    public int findKthLargest(int[] nums, int k) {
        /* Normally build a heap */
        // var heap = new MinHeap<Integer>(k);
        // for (var n : nums){
        //     if (heap.size() < k){
        //         heap.add(n);
        //     }
        //     else if (n > heap.peek()){
        //         heap.popMin();
        //         heap.add(n);
        //     }
        // }
        // return heap.peek();
        
        /* Use my own heap and do Heapify */
        MinHeap<Integer> heap;
        if (k <= nums.length / 2){ // better use MaxAHeap
            heap = new MinHeap<>(
                Arrays.stream(nums).boxed().toArray(Integer[]::new), // one line conversion
                (a, b) -> b - a
            );
        }
        else {
            heap = new MinHeap<Integer>(
                Arrays.stream(nums).boxed().toArray(Integer[]::new) // one line conversion
            );
            k = nums.length - k + 1;
        }
        while (--k > 0){ heap.popMin(); }
        return heap.peek();
    }
}
// @lc code=end

