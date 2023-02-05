/*
 * @lc app=leetcode id=381 lang=cpp
 *
 * [381] Insert Delete GetRandom O(1) - Duplicates allowed
 */

#include <climits>
#include <random>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
/** 
 * Accept: runtime 91.68%
 *          memory 47.23%
 */
class RandomizedCollection {
private:
    using ll = long long;
    using vi = vector<ll>::iterator;
    using vv = vector<vi>;
    const ll INVALID = LONG_LONG_MIN;
    vector<ll> data;
    vv removed_list;
    unordered_map<ll, vv> dict;
public:
    RandomizedCollection() {
        data.reserve(1 << 16);
    }
    
    bool insert(int val) {
        vi it;
        if (!removed_list.empty()) {
            it = removed_list.back();
            *it = val;
            removed_list.pop_back();
        }
        else {
            data.push_back(val);
            it = data.end() - 1;
        }
        if (dict.find(val) != dict.end()) {
            dict[val].push_back(it);
            return false;
        }
        else {
            dict.insert({ val, vv { it } });
            return true;
        }
    }
    
    bool remove(int val) {
        bool res = dict.find(val) != dict.end();
        if (res) {
            auto &v = dict[val];
            auto it = v.back();
            v.pop_back();
            if (v.empty())
                dict.erase(dict.find(val));
            *it = INVALID; // impossible number
            removed_list.push_back(it);
        }
        return res;
    }
    
    int getRandom() {
        uniform_int_distribution<> dis(0, data.size() - 1);

        static random_device rd;
        static mt19937 gen(rd());
        ll res;
        do {
            res = *(data.begin() + dis(gen));
        } while (res == INVALID);

        return res;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

