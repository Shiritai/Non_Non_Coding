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
 * Accept: runtime 90.41%
 *          memory 65.58%
 */
class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> min_hp; // max_heap <-> min heap
    priority_queue<int, vector<int>, less<int>> max_hp; // max_heap <-> min heap
    int sz;
    
public:
    MedianFinder(): sz(0) {}
    
    void addNum(int num) {
        int cur = sz++ & 1;
        if (cur)
            min_hp.push(num);
        else 
            max_hp.push(num);
    }

    double findMedian() {
        if (sz == 1) 
            return max_hp.top();
        int max_fnt, min_fnt;
        while ((max_fnt = max_hp.top()) > 
               (min_fnt = min_hp.top())) {
            min_hp.pop();
            min_hp.push(max_fnt);

            max_hp.pop();
            max_hp.push(min_fnt);
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

