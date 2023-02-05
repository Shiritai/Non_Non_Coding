/*
 * @lc app=leetcode id=432 lang=cpp
 *
 * [432] All O`one Data Structure
 */

#include <cstddef>
#include <string>
#include <list>
#include <iterator>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/** 
 * Accept: runtime 72/52%
 *          memory 66.72%
 */

// @lc code=start
class AllOne {
private:
    struct node {
        int n; 
        unordered_set<string> content; 
    };

    list<node> ls; // sorted list
    unordered_map<string, list<node>::iterator> dict;
public:
    AllOne() {}
    
    void inc(string key) {
        auto it = dict.find(key);
        if (it == dict.end()) { // 字不存在
            auto front = ls.begin();
            if (front != ls.end() && front->n == 1) 
                front->content.insert(key);
            else {
                ls.push_front({ 1, { key } } );
                front = ls.begin();
            }
            dict[key] = front;
        }
        else { // 字存在
            auto cur = it->second;
            int cur_val = cur->n;
            cur->content.erase(key);
            auto nxt = cur;
            ++nxt;
            if (nxt != ls.end() && nxt->n == cur_val + 1) {
                nxt->content.insert(key);
                dict[key] = nxt;
            }
            else {
                ls.insert(nxt, { cur_val + 1, { key } });
                dict[key] = --nxt;
            }
            if (cur->content.empty())
                ls.erase(cur);
        }
    }
    
    void dec(string key) {
        auto it = dict.find(key);
        auto cur = it->second;
        int cur_val = cur->n;
        cur->content.erase(key);
        if (cur_val != 1) {
            auto nxt = cur;
            --nxt;
            if (nxt != ls.end() && nxt->n == cur_val - 1) {
                nxt->content.insert(key);
                dict[key] = nxt;
            }
            else {
                ls.insert(++nxt, { cur_val - 1, { key } });
                dict[key] = --nxt;
            }
        }
        else 
            dict.erase(key);
        if (cur->content.empty())
            ls.erase(cur);
    }
    
    string getMaxKey() {
        if (ls.empty())
            return "";
        return *ls.rbegin()->content.begin();
    }
    
    string getMinKey() {
        if (ls.empty())
            return "";
        return *ls.begin()->content.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end

