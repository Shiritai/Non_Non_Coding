/*
 * @lc app=leetcode id=403 lang=cpp
 *
 * [403] Frog Jump
 */

#include <algorithm>
#include <iterator>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    /** 
     * Accept: runtime 63.31%
     *          memory 59.67%
     */
    bool canCross(vector<int>& stones) {
        const int len = stones.size();
        if (len < 2)
            return true;
        if (stones[1] != 1)
            return false;
        
        unordered_map<int, size_t> check_list;
        auto not_found = check_list.end();

        for (int i = 0; i < len; ++i)
            check_list[stones[i]] = i;
        
        vector<unordered_set<int>> jumps(len);
        jumps[1].insert(1);
        for (int i = 1; i < len; ++i) {
            for (auto diff: jumps[i]) {
                auto it = not_found;
                if ((it = check_list.find(stones[i] + diff)) != not_found) 
                    jumps[it->second].insert(diff);
                diff -= 1;
                if (diff > 0 && (it = check_list.find(stones[i] + diff)) != not_found) 
                    jumps[it->second].insert(diff);
                diff += 2;
                if ((it = check_list.find(stones[i] + diff)) != not_found) 
                    jumps[it->second].insert(diff);
            }
        }
        return !jumps[len - 1].empty();
    }
};
// @lc code=end

