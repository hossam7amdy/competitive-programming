#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



bool cmp(const pair<int,int> &p1, const pair<int,int> &p2){
    return p1.second < p2.second;
}

int main(){
    int n, r;
    long long avg;
    cin >> n >> r >> avg;
    vector<pair<int, int>> exams(n);
    avg *= n;

    long long sum{};
    for(int i = 0; i < n; ++i){
        cin >> exams[i].first >> exams[i].second;
        sum += exams[i].first;
    }

    long long cnt{};
    if(sum >= avg){
        cout << cnt << "\n";
        return 0;
    }
    sort(exams.begin(), exams.end(), cmp);
    for(int i = 0; i < n; ++i){
        auto p = exams[i];

        long long cur = min(avg - sum, (long long)r - (long long)p.first);

        sum += cur;
        cnt += cur * p.second;

        if(sum >= avg)
            break;
    }

    cout << cnt << "\n";

    return 0;
}
