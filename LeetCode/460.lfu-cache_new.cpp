/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */

// @lc code=start

#include <functional>
#include <unordered_map>
#include <queue>
#include <list>
#include <iostream>

using namespace std;

class LFUCache {
private:
    struct entry {
        int val;
        int cnt;
        int age; // record the born time
        unordered_map<int, list<int>>::iterator it;
    };

    unordered_map<int, entry> data;
    unordered_map<int, list<int>> freq_ls;
    int min_fq;
    int global_age;
public:
    LFUCache(int capacity): global_age(0) {}
    
    int get(int key) {
        return -1;
    }
    
    void put(int key, int value) {
        auto data_it = data.find(key);
        entry to_add {
            .val = value,
            .cnt = 1,
            .age = global_age++,
            .it = freq_ls.end()
        };
        if (data_it != data.end()) 
            freq_ls.erase(data_it->second.it);
        if (freq_ls.find(1) != freq_ls.end()) {
            freq_ls[1].push_front(key);
        }
        data.insert({ key, to_add });

    }
};
// @lc code=end

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */



