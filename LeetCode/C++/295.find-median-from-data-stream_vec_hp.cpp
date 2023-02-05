/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
/** 
 * Accept: runtime 73.30%
 *          memory 65.58%
 */
class MedianFinder {
private:
    vector<int> data[2]; // max_heap <-> min heap
    function<bool(double, double)> cmp_fn[2];
    int sz;
    
public:
    MedianFinder(): sz(0) {
        auto & max_hp = data[0], & min_hp = data[1];
        auto & max_fn = cmp_fn[0], & min_fn = cmp_fn[1];
        max_fn = less<int>();
        min_fn = greater<int>();
        make_heap(max_hp.begin(), max_hp.end(), max_fn);
        make_heap(min_hp.begin(), min_hp.end(), min_fn);
    }
    
    void addNum(int num) {
        int cur = sz++ & 1;
        auto & v = data[cur];
        auto & cmp = cmp_fn[cur];
        v.push_back(num);
        push_heap(v.begin(), v.end(), cmp);
    }
    
    double findMedian() {
        auto & max_hp = data[0], & min_hp = data[1];
        auto & max_fn = cmp_fn[0], & min_fn = cmp_fn[1];

        if (sz == 1) 
            return max_hp.front();

        int max_fnt, min_fnt;
        while ((max_fnt = max_hp.front()) > 
               (min_fnt = min_hp.front())) {
            pop_heap(min_hp.begin(), min_hp.end(), min_fn);
            min_hp.pop_back();
            min_hp.push_back(max_fnt);
            push_heap(min_hp.begin(), min_hp.end(), min_fn);

            pop_heap(max_hp.begin(), max_hp.end(), max_fn);
            max_hp.pop_back();
            max_hp.push_back(min_fnt);
            push_heap(max_hp.begin(), max_hp.end(), max_fn);
        }
        return sz & 1 ? max_fnt : (max_fnt + min_fnt) / 2.;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

