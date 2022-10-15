#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> CELL;
#define X first
#define Y second

const double OO = 9999;
vector<double> alpha(26, OO);
vector<bool> exist(26, false);
vector<CELL> shift;

void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
void readFile(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

double ecl_dis(const int &x1, const int &y1, const int &x2, const int &y2){
    return sqrt(pow(abs(y1-y2),2) + pow(abs(x1-x2),2));
}

int solve(const int &x) { // O(t)
    int t, cnt = 0;
    cin >> t;
    while(t--){
        char ch;
        cin >> ch;

        if(!exist[tolower(ch)-'a'] || isupper(ch) && alpha[tolower(ch)-'a'] == OO)
            return -1;
        if(isupper(ch) && alpha[tolower(ch)-'a'] > x)
            ++cnt;
    }

    return cnt;
}


int main() {
    fast();

    int n,m,x;
    cin >> n >> m >> x;
    vector<vector<char>> keyboard(n, vector<char>(m));

    for(int r = 0; r < n; ++r){
        for(int c = 0; c < m; ++c){
            cin >> keyboard[r][c];
            if(keyboard[r][c] == 'S')
                shift.push_back({r,c});
            else
                exist[keyboard[r][c] - 'a'] = true;
        }
    }

    for(CELL cell : shift){ // O((nm)^2)
        for(int r = 0; r < n; ++r){
            for(int c = 0; c < m; ++c){
                if(keyboard[r][c] == 'S')
                    continue;

                int idx = keyboard[r][c] - 'a';
                alpha[idx] = min(alpha[idx], ecl_dis(r,c, cell.X, cell.Y));
            }
        }
    }

    cout << solve(x) << endl;

    return 0;
}
