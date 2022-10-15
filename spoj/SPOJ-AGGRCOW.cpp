#include <bits/stdc++.h>
using namespace std;

void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

bool possible(const vector<int> &pos, const int &cows, int cur_dist) { // O(n)
    int cnt = 1, cur_pos = 0;
    for(int i = 1; i < (int)pos.size(); ++i){
        if(cur_dist <= pos[i] - pos[cur_pos])
            cur_pos = i, ++cnt;
        if(cnt >= cows)
            return true;
    }
    return false;
}

int getDist(const vector<int> &pos, const int &cows, int max_dist) { // O(logn)
    int st = 0, en = max_dist;

    while(st <= en) {
        int mid = st + (en - st) / 2;

        if(possible(pos, cows, mid))
            st = mid + 1, max_dist = mid;
        else
            en = mid - 1;
    }

    return max_dist;
}

int main(){ // over all => O(nlogn)
    fast();

    int test;
    cin >> test;
    while(test--) {
        int N,C;
        cin >> N >> C;
        vector<int> positions(N);
        for(int i = 0; i < N; ++i)
            cin >> positions[i];

        sort(positions.begin(), positions.end()); // O(nlogn)

        int max_dist = getDist(positions, C, positions.back());
        cout << max_dist << endl;
    }

    return 0;
}
