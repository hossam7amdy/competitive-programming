#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> CELL;
#define r first
#define c second
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void print(const vector<vector<int>> &grid) {
    int rows = (int)grid.size(), cols = (int)grid[0].size();
    for(int r = 0; r < rows; ++r){
        for(int c = 0; c < cols; ++c){
            cout << grid[r][c];
            if(c + 1 < cols)
                cout << " ";
        }
        cout << "\n";
    }
}

CELL getCELL(const string &str){
    const int CYCLE {26};
    int col = 0;
    string row;
    for(int i = 0; i < (int)str.size(); ++i){
        if(isupper(str[i]))
            col = col * CYCLE + (str[i] - 'A' + 1);
        else
            row += str[i];
    }
    return {stoi(row) - 1, col - 1};
}

int compute(vector<vector<int>> &grid, const CELL &cell, vector<vector<string>> &formulas){
    int nr = cell.r, nc = cell.c;
    string formula = formulas[nr][nc];
    if(formula.empty())
        return grid[nr][nc];

    string s;
    vector<string> notations;
    for(int i = 0; i < (int)formula.length(); ++i){
        if(formula[i] == '+'){
            notations.push_back(s);
            s.clear();
            continue;
        }
        s += formula[i];
    }
    formulas[nr][nc].clear();

    for(int i = 0; i < (int)notations.size(); ++i)
        grid[nr][nc] += compute(grid, getCELL(notations[i]), formulas);

    return grid[nr][nc];
}

int main(){
    fast();
    int t;
    cin >> t;
    while(t--){
        int COLS, ROWS;
        cin >> COLS >> ROWS;
        vector<vector<int>> grid(ROWS, vector<int>(COLS));
        vector<vector<string>> formulas(ROWS, vector<string>(COLS));

        string input;
        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                cin >> input;
                if(input.front() != '=')
                    grid[r][c] = stoi(input);
                else
                    formulas[r][c] = input.substr(1)+'+';
            }
        }

        for(int r = 0; r < ROWS; ++r)
            for(int c = 0; c < COLS; ++c)
                if(!formulas[r][c].empty())
                    grid[r][c] = compute(grid, {r,c}, formulas);

        print(grid);
    }

    return 0;
}
