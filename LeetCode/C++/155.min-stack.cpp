/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */
#include <vector>

using namespace std;

// @lc code=start
/** 
 * Accept: runtime: 60.3%
 *         memory:  99.38%
 *
 */
class MinStack {
public:
    MinStack() {}
    
    void push(int val) {
        data.push_back(val);
        if (min_ls.empty() || min_ls.back() >= val)
            min_ls.push_back(val);
    }
    
    void pop() {
        if (!min_ls.empty() && data.back() == min_ls.back())
            min_ls.pop_back();
        data.pop_back();
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return min_ls.back();
    }
private:
    vector<int> data;
    vector<int> min_ls;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

