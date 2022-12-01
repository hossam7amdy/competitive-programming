#include<bits/stdc++.h>
using namespace std;

/*
    Determine if a 9 x 9 Sudoku board is valid.

    SOLUTION: As problem said
    - validate row*cols & cols*row
    - validate each sub 3*3 box

    >> Complexity:
        - Time O(n^2)
        - Space O(n)
*/

class Solution {
public:
    bool isValidSudoku(const vector<vector<char>>& board) {
        for(int r = 0; r < board.size(); ++r){
            memset(rows, 0, sizeof(rows));
            memset(cols, 0, sizeof(cols));
            for(int c = 0; c < board.size(); ++c){
                char row_cell = board[r][c];
                char col_cell = board[c][r];

                if(row_cell != '.'){
                    int row_idx = toInt(row_cell);
                    if(rows[row_idx])
                        return false;
                    rows[row_idx] = 1;
                }

                if(col_cell != '.'){
                    int col_idx = toInt(col_cell);
                    if(cols[col_idx])
                        return false;
                    cols[col_idx] = 1;
                }

                if(r % 3 == 0 && c % 3 == 0)
                    if(!okBlock(board, r,c, r+3, c+3))
                        return false;
            }
        }

        return true;
    }

private:
    static const int MAX = 10;
    bool rows[MAX];
    bool cols[MAX];
    bool block[MAX];

    int toInt(const char &digit){
        return digit - '0';
    }

    bool okBlock(const vector<vector<char>> &board,
               int start_r, int start_c, int end_r, int end_c){
        memset(block, 0, sizeof(block));
        for(int r = start_r; r < end_r; ++r){
            for(int c = start_c; c < end_c; ++c){
                char ch = board[r][c];
                int idx = toInt(ch);
                if(ch == '.')
                    continue;

                if(block[idx])
                    return false;

                block[idx] = 1;
            }
        }
        return true;
    }
};

int main() {

    return 0;
}
