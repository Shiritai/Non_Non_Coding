/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const string::size_type s_l = s.length();
        unordered_multimap<int, int> mp;
        unordered_set<int> disjoint_set;
        string::size_type end_test = 0;
        for (auto w: wordDict) { // word to mark
            cout << w << "\n";
            string::size_type w_l = w.length(), 
                              cur = s.find(w), nxt;
            if (cur == std::string::npos) 
                continue;
            while ((cur = s.find(w, cur)) < string::npos) {
                nxt = cur + w_l; // calculate the real ending index
                end_test = max(end_test, nxt);
                mp.insert(pair<int, int>(cur, nxt));
                for (int i = cur; i < nxt; ++i) {
                    disjoint_set.insert(i);
                }
                // cout << cur << ", " << nxt << endl;
                ++cur;
            }
        }
        // cout << end_test << " should match with " << s_l << endl;
        // if (end_test != s_l) {
        //     return false;
        // }
        // cout << "Meow\n";
        for (int i = 0; i < s_l; ++i)
            if (disjoint_set.find(i) == disjoint_set.end())
                return false;
        vector<unordered_multimap<int, int>::iterator> stack, // calling stack
                                             backtrace; // backtrace nodes
        auto cur = mp.find(0), end = mp.end();
        while (cur != end && !cur->first) { // push frontier entries
            stack.emplace_back(cur++);
        }
        while (!stack.empty()) {
            cur = stack.back();
            stack.pop_back();
            // cout << "Current node: " << cur->first << " -> " << cur->second << endl;
            if (cur->second == s_l) {
                backtrace.push_back(cur);
                // cout << "Generating backtrace path\n";
                // for (auto _it: backtrace) {
                //     cout << _it->first << " -> ";
                // }
                // cout << "[end]\n";
                return true;
            }
            auto nxt = mp.find(cur->second);
            if (nxt == end) {
                if (backtrace.empty()) {
                    continue;
                }
                cur = backtrace.back();
                backtrace.pop_back();
            }
            else {
                // record the current node for backtrace
                backtrace.emplace_back(cur);
                // store the available nodes to the calling stack
                while (nxt != end && nxt->first == cur->second) {
                    stack.emplace_back(nxt++);
                }
            }
        }
        return false;
    }
};
// @lc code=end

