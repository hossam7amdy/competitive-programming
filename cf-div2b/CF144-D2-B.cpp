#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> CELL;
#define x first
#define y second
#define ll long long

void fast_IO(){
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

int main(){
    fast_IO();

    int x1,y1, x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if(x1 > x2)
        swap(x1, x2);
    if(y1 > y2)
        swap(y1, y2);

    vector<CELL> coords;
    for(int i = x1; i <= x2; ++i){
        for(int j = y1; j <= y2; ++j){
            if(i == x1 || i == x2)
                coords.push_back({i,j});
            else if(j == y1)
                coords.push_back({i,y1});
            else if(j == y2)
                coords.push_back({i,y2});
        }
    }

    int n;
    cin >> n;
    while(n--){

        int x,y;
        double r;
        cin >> x >> y >> r;

        auto it = coords.begin();
        while(it != coords.end() && !coords.empty()){
            CELL cell = *it;
            if(ecl_dis(cell.x, cell.y, x, y) <= r)
                coords.erase(it);
            else
                ++it;
        }
    }

    cout << (int)coords.size() << "\n";

    return 0;
}
