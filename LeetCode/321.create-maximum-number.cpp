/*
 * @lc app=leetcode id=321 lang=cpp
 *
 * [321] Create Maximum Number
 */

#include <vector>
#include <list>

using namespace std;

// @lc code=start
class Solution {
public:
    class my_it {
    public:
        my_it(vector<int> & v): it(v.begin()), remain(v.size()) {}
        vector<int>::iterator& operator*() { return it; }
        my_it operator+(int offset) { return my_it(*this, offset); }
        my_it& operator++() { ++it; --remain; return *this; }
        my_it operator++(int) {
            my_it ret(*this, 0);
            ++it; --remain;
            return ret;
        }
        bool end() { return !remain; }
    private:
        my_it(my_it & mi, int offset): 
            it(mi.it + offset), remain(mi.remain - offset) {}
        vector<int>::iterator it;
        int remain;
    };

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        list<int> l1, l2;
        auto i1 = nums1.begin(), i2 = nums2.begin();
        while (k > 0) {
            // build monotonic list
            while (*i1 < *(i1 + 1)) 
                l1.push_back(*++i1);
            // build monotonic list
            while (*i2 < *(i2 + 1)) 
                l2.push_back(*++i2);
            // if ()
        }
    }
};
// @lc code=end