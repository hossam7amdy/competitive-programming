#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

/// https://codeforces.com/problemset/problem/767/A

int main(){
    priority_queue<int> pq;
    int num, cnt;
    cin >> num;
    cnt = num;

    while(num--){
        int x;
        cin >> x;
        pq.push(x);
        if(x==cnt){
            while(!pq.empty() && cnt==pq.top()){
                cout << pq.top() << " ";
                pq.pop();
                --cnt;
            }
        }
        if(num)
            cout << "\n";
    }

    return 0;
}
