/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

#include <algorithm>
#include <climits>
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        const int row = dungeon.size(),
                  col = dungeon.front().size();
        
        vector<vector<pair<int, int>>> table(row, vector<pair<int, int>>(col));
        
        /* pair< current_hp , lowest_hp > */
        table[0][0] = pair<int, int>(dungeon[0][0], min(1, dungeon[0][0]));
        for (int j = 1; j < col; ++j) {
            table[0][j].first = table[0][j - 1].first + dungeon[0][j];
            table[0][j].second = min(table[0][j - 1].second, table[0][j].first);
        }
        for (int i = 1; i < row; ++i) {
            table[i][0].first = table[i - 1][0].first + dungeon[i][0];
            table[i][0].second = min(table[i - 1][0].second, table[i][0].first);
            for (int j = 1; j < col; ++j) {
                if (table[i - 1][j].second > table[i][j - 1].second) { // use up
                    table[i][j].first = table[i - 1][j].first + dungeon[i][j];
                    table[i][j].second = min(table[i - 1][j].second, table[i][j].first);
                }
                else { // use left
                    table[i][j].first = table[i][j - 1].first + dungeon[i][j];
                    table[i][j].second = min(table[i][j - 1].second, table[i][j].first);
                }
            }
        }

        for (auto &vp: table) {
            for (auto &p: vp) {
                cout << p.first << ' ';
            }
            cout << endl;
        }
        cout << "------------" << endl;
        for (auto &vp: table) {
            for (auto &p: vp) {
                cout << p.second << ' ';
            }
            cout << endl;
        }

        
        return max(1, 1 - table[row - 1][col - 1].second);
    }
};
/* 

 1, -3,  3
 0, -2,  0
-3, -3. -3

 1, -2,  1
 1, -1, -1
-2, -4, -4

*/
// @lc code=end

