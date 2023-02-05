#ifndef I_HEAP_H
#define I_HEAP_H

#include <cstdlib>

namespace eroikoDS {
/**
 * Index Min Heap, also named as indexed priority queue.
 * Notice that its max size is static, should be decided when initializing.
 */
template <typename T>
class i_heap {
public:
    /* Alias type of comparator */
    using cmp_fn = bool(*)(T&,T&);
private:
    /* Basic properties */
    int cap, sz;

    /* Original data array */
    T * arr;

    /* Index heap with reverse subscript functionality */
    int * i_ls, * r_ls;

    /** 
     * Comparator
     * lessThan(T & a, T & b) -> true if a is less than b, 
     * otherwise false
     */
    cmp_fn lessThan;


    /** 
     * This is the default lessThan function
     */
    static bool default_fn(T & a, T & b);

    /** 
     * This is the pop method that only deal with 
     * "deleting process" for any "popping" method
     */
    void _pop();

    /**
     * Try to shift down an element in i_ls, O(log(n))
     * @param i the index in i_ls to shift down
     */
    void shift_down(int i);

    /**
     * Try to shift up an element in i_ls, O(log(n))
     * @param i the index in i_ls to shift up
     */
    void shift_up(int i);

public:
    /** 
     * Initialize an index min heap with it's size, 
     * the comparator will default to be the "<" operator. 
     * Be sure to override "<" operator if needed, O(n)
     * @param cap size of index minheap
     */
    i_heap(int cap);

    /** 
     * Initialize an index min heap with it's size and
     * comparator, O(n)
     * @param cap size of index minheap
     * @param lessThan Comparator
     * lessThan(T & a, T & b) -> true if a is LESS THAN b, 
     * vice versa
     */
    i_heap(int cap, cmp_fn lessThan);

    ~i_heap();

    /** 
     * Push an element to the heap at index i, O(log(n))
     * @param val data to push
     * @param i push val to index i
     */
    void push(T & val, int i);

    /** 
     * Push an element to the heap at index i, O(log(n))
     * @param val data to push
     * @param i push val to index i
     */
    void push(T && val, int i);

    /** 
     * Peek the top element in heap, O(1)
     */
    T & top();

    /** 
     * Peek the index of the top element in i_heap, O(1)
     */
    int top_id();

    /** 
     * Pop the top element, O(log(n))
     * It's better to use pop_id() rather then this function
     */
    T pop();

    /** 
     * Pop the index of the top element, O(log(n))
     */
    int pop_id();

    /**
     * O(1)
     */
    int size(); bool empty(); int capacity();

    /** 
     * Check whether the element at index i exist in i_heap, O(1)
     * @param i the index to check existence
     */
    bool contain(int i);

    /** 
     * O(1)
     */
    T operator[](int i) const;

    /** 
     * Set value of index i, O(1)
     */
    T & operator[](int i);

    /** 
     * Try to shift up or shift down if needed
     * @param i the index to check and try
     */
    void adjust(int i);

    /** 
     * Assign the element at position i with val
     */
    void adjust(int i, T val);
};

template <typename T>
bool i_heap<T>::default_fn(T & a, T & b){ return a < b; }

template <typename T>
i_heap<T>::i_heap(int cap): i_heap<T>(cap, i_heap<T>::default_fn) {}

template <typename T>
i_heap<T>::i_heap(int cap, cmp_fn lessThan): cap(cap + 1), sz(0), 
    arr((T *) malloc(sizeof(T) * (cap + 1))), i_ls(new int [cap + 1]),
    r_ls(new int[cap + 1]), lessThan(lessThan) { // Deliberately left index 0 empty
    memset(r_ls, 0, sizeof(int) * (this->cap)); // 此時 this->cap 已為 cap + 1
}

template <typename T>
i_heap<T>::~i_heap(){
    free(arr);
    delete [] i_ls;
    delete [] r_ls;
}

template <typename T>
void i_heap<T>::push(T & val, int i){
    push((T&&) val, i);
}

template <typename T>
void i_heap<T>::push(T && val, int i){
#ifdef SAFE_MODE
    if (i < 0 || i >= cap)
        throw "Index MinHeap push error, index out of bound";
    if (sz + 1 == cap)
        throw "Index MinHeap push error, not enough space, try to change by subscription rather than push it";
#endif
    arr[++i] = val; // 內部以 1 為始，故加一
    i_ls[++sz] = i; // i_ls (heap) 新增節點在最後
    r_ls[i] = sz; // 為新節點維護資料索引方法
    shift_up(sz);
}

template <typename T>
T & i_heap<T>::top(){
#ifdef SAFE_MODE
    if (!sz)
        throw "Index MinHeap is empty";
#endif
    return arr[i_ls[1]]; // arr 跟 i_ls 的首位都是 1，不用把索引位移
}

template <typename T>
int i_heap<T>::top_id(){
#ifdef SAFE_MODE
    if (!sz)
        throw "Index MinHeap is empty";
#endif
    return i_ls[1] - 1; // For user, index 0 is the beginning
}

template <typename T>
void i_heap<T>::_pop(){
    i_ls[1] = i_ls[sz];
    r_ls[i_ls[1]] = 1; // 維護索引性質
    r_ls[i_ls[sz--]] = 0; // 末位已經移到首位，故末位從 heap (i_ls) 刪除
    shift_down(1);
}

template <typename T>
T i_heap<T>::pop(){
#ifdef SAFE_MODE
    if (!sz)
        throw "Index MinHeap is empty";
#endif
    T ret = arr[i_ls[1]];
    _pop();
    return ret;
}

template <typename T>
int i_heap<T>::pop_id(){
#ifdef SAFE_MODE
    if (!sz)
        throw "Index MinHeap is empty";
#endif
    int ret = i_ls[1] - 1; // For user, index 0 is the beginning
    _pop();
    return ret;
}

template <typename T>
int i_heap<T>::size(){ return sz; }

template <typename T>
bool i_heap<T>::empty(){ return sz == 0; }

template <typename T>
int i_heap<T>::capacity(){ return cap; }

template <typename T>
bool i_heap<T>::contain(int i){
#ifdef SAFE_MODE
    if (i >= cap || i < 0)
        throw "Index MinHeap subscription error, index out of bound";
#endif
    return r_ls[i + 1] != 0;
}

template <typename T>
T i_heap<T>::operator[](int i) const {
#ifdef SAFE_MODE
    if (i >= cap || i < 0)
        throw "Index MinHeap subscription error, index out of bound";
    if (!contain(i))
        throw "This Index MinHeap doesn't contains this element";
#endif
    return arr[i + 1];
}

template <typename T>
T & i_heap<T>::operator[](int i){
#ifdef SAFE_MODE
    if (i >= cap || i < 0)
        throw "Index MinHeap subscription error, index out of bound";
    if (!contain(i))
        throw "This Index MinHeap doesn't contains this element";
#endif
    return arr[i + 1];
}

template <typename T>
void i_heap<T>::shift_up(int i){
    int ori = i_ls[i]; // 源位置
    int prt;
    while (i > 1 && lessThan(arr[ori], arr[i_ls[(prt = i >> 1)]])){
        i_ls[i] = i_ls[prt];
        r_ls[i_ls[i]] = i;
        i = prt;
    }
    i_ls[i] = ori;
    r_ls[i_ls[i]] = i;
}

template <typename T>
void i_heap<T>::shift_down(int i){
    int ori = i_ls[i]; // 源位置
    int ch = i << 1; // 子索引
    while (ch <= sz){
        if (ch + 1 <= sz && lessThan(arr[i_ls[ch + 1]], arr[i_ls[ch]]))
            ++ch;
        if (lessThan(arr[ori], arr[i_ls[ch]]))
            break;
        i_ls[i] = i_ls[ch];
        r_ls[i_ls[i]] = i;
        i = ch;
        ch <<= 1;
    }
    i_ls[i] = ori;
    r_ls[i_ls[i]] = i;
}

template <typename T>
void i_heap<T>::adjust(int i){
#ifdef SAFE_MODE
    if (i < 0 || i >= sz)
        throw "IndexMinHeapAdjustException: index out of bound";
#endif
    int r = r_ls[i + 1];
    shift_up(r); shift_down(r);
}

template <typename T>
void i_heap<T>::adjust(int i, T val){
#ifdef SAFE_MODE
    if (i < 0 || i >= sz)
        throw "IndexMinHeapAdjustException: index out of bound";
#endif
    arr[++i] = val;
    int r = r_ls[i];
    shift_up(r); shift_down(r);
}

}

#endif