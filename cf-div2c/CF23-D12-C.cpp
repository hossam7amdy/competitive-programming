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

struct box {
    int id, apples, oranges;

    bool operator < (const box &other){
        return oranges < other.oranges;
    }
};

int main(){
    fast_IO();

    int cases;
    cin >> cases;

    while(cases--){
        int n;
        cin >> n;
        n = n * 2 - 1;

        cout << "YES\n";

        ll allApples = 0;
        vector<box> boxes(n); // assume zero based
        for(int i = 0; i < n; ++i){

            int apples, oranges;
            cin >> apples >> oranges;
            boxes[i] = {i+1, apples, oranges};
            allApples += apples;
        }
        sort(boxes.begin(), boxes.end()); // by orange

        ll oddSum = 0; // apples at odd positions
        for(int i = 0; i < n; i+=2)
            oddSum += boxes[i].apples;

        int i = oddSum*2 >= allApples ? 0 : 1;
        if(i == 1)
            cout << boxes.back().id << " ";

        for(; i < (int)boxes.size(); i += 2)
            cout << boxes[i].id << " ";
        cout << "\n";
    }

    return 0;
}
