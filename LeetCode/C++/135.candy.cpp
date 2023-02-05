/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    
    enum type_t { ASCEND = 2, DESCEND = 1, FLAT = 0 };

    inline type_t next_state(int cur, int last) {
        int relation = cur - last;
        return (type_t) ((relation != 0) + (relation > 0));
    }
    
    /** 
     * Accept: runtime 89.74%
     *         memory 98.58%
     */
    int candy(vector<int>& ratings) {
        const int len = ratings.size();
        if (len == 1) // guard
            return 1;

        int start, res, n, asc_tail = 0, 
            end = 2, last_r = ratings[1];
        start = res = n = 0;

        type_t type = next_state(ratings[1], ratings[0]), 
               last_type;
        
        if (type == FLAT)
            ++res;

        for (; end != len; ++end) {
            int r = ratings[end];
            type_t nxt_type = next_state(r, last_r);

            switch (type) {
            case ASCEND:
                if (nxt_type != ASCEND) {
                    n = end - start;
                    res += (n * (n + 1)) >> 1;
                    if (last_type == DESCEND)
                        --res;
                    asc_tail = n;
                    start = end - 1;
                    last_type = type;
                    type = nxt_type;
                }
                break;
            case DESCEND:
                if (nxt_type != DESCEND) {
                    n = end - start;
                    res += (n * (n + 1)) >> 1;
                    if (last_type == ASCEND)
                        res -= min(n, asc_tail);
                    start = end - 1;
                    last_type = type;
                    type = nxt_type;
                }
                break;
            case FLAT:
                if (nxt_type != FLAT) {
                    res += end - start - 2;
                    start = end - 1;
                    last_type = type;
                    type = nxt_type;
                }
                break;
            }

            last_r = r;
        }

        cout << res << endl;

        switch (type) {
        case ASCEND:
            n = end - start;
            res += (n * (n + 1)) >> 1;
            if (last_type == DESCEND)
                --res;
            break;
        case DESCEND:
            n = end - start;
            res += (n * (n + 1)) >> 1;
            cout << last_type << endl;
            if (last_type == ASCEND)
                res -= min(n, asc_tail);
            cout << res << endl;
            break;
        case FLAT:
            res += end - start - 1;
            break;
        }
        
        return res;
    }
};
// @lc code=end

