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
        unordered_map<string, bool> detected;
        for (auto& w: wordDict)
            detected[w] = true;
        const size_t len = s.size();
        vector<pair<int, int>> stack;
        stack.reserve(len);
        int start = 0, n = 1;

        string sub;
        bool result, notfound;
        while (true) {
            if (start + n <= len) {
                auto history = detected.find((sub = s.substr(start, n)));
                notfound = history == detected.end();
                if ((!notfound && history->second) || 
                    (result = detected.find(sub) != detected.end())) {
                    if (start + n == len)
                        return true;
                    if (notfound)
                        detected[sub] = result;
                    // cout << "start: " << start << ", n: " << n << ", substr: " << s.substr(start, n) << endl;
                    stack.push_back(pair<int, int>(start, n));
                    start += n;
                    n = 1;
                }
                else 
                    ++n;
            }
            else if (!stack.empty()) {
                auto p = stack.back();
                stack.pop_back();
                start = p.first;
                n = p.second + 1;
            }
            else break;
        }
        return false;
    }
};
// @lc code=end

