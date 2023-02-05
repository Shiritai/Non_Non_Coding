#include <vector>
#include <iostream>
#include <memory.h>

using namespace std;

class Solution {
public:
    bool isValidSudokuArray(vector<vector<char>>& board) {
        bool row[9], col[9], box[9]; // recorder
        int r = 0, c = 0;
        for (int i = 0; i < 9; ++i) {
            // initialize: erase mark
            memset(row, false, sizeof(row));
            memset(col, false, sizeof(col));
            memset(box, false, sizeof(box));
            // check and update with loop
            for (int j = 0; j < 9; ++j) {
                // change box index
                c = (i % 3) * 3 + j % 3;
                r = (i / 3) * 3 + j / 3;
                // fetch accessing index
                const int now_c = board[j][i] - '1';
                const int now_r = board[i][j] - '1';
                const int now_b = board[r][c] - '1';
                // check
                if (now_r >= 0) {
                    if (row[now_r]) return false;
                    row[now_r] = true; // mark
                }
                if (now_c >= 0) {
                    if (col[now_c]) return false;
                    col[now_c] = true; // mark
                }
                if (now_b >= 0) {
                    if (box[now_b]) return false;
                    box[now_b] = true; // mark
                }
            }
        }
        return true;
    }

    bool isValidSudokuBitwise(vector<vector<char>>& board) {
        short row, col, box; // recorder
        int r = 0, c = 0;
        for (int i = 0; i < 9; ++i) {
            // initialize: erase mark
            row = col = box = 0;
            // check and update with loop
            for (int j = 0; j < 9; ++j) {
                // change box index
                c = (i % 3) * 3 + j % 3;
                r = (i / 3) * 3 + j / 3;
                // fetch accessing index
                const int now_c = board[j][i] - '1';
                const int now_r = board[i][j] - '1';
                const int now_b = board[r][c] - '1';
                // check
                if (now_r >= 0) {
                    if (row & (1 << now_r)) return false;
                    row |= (1 << now_r); // mark
                }
                if (now_c >= 0) {
                    if (col & (1 << now_c)) return false;
                    col |= (1 << now_c); // mark
                }
                if (now_b >= 0) {
                    if (box & (1 << now_b)) return false;
                    box |= (1 << now_b); // mark
                }
            }
        }
        return true;
    }
};

int main(void) {}