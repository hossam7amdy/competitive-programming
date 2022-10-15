#include<iostream>
#include<queue>
using namespace std;

/// https://codeforces.com/contest/160/problem/A

int main(){
    priority_queue<int> pq;
    int n, c=0, sum=0, mysum=0;

    cin >> n;

    if(n==1){
        cout << n;
        return 0;
    }

    while(n--){
        int val;
        cin >> val;
        sum+=val;
        pq.push(val);
    }

    while(!pq.empty()){
        mysum+=pq.top();
        sum-=pq.top();
        c++;
        pq.pop();
        if(mysum>sum)
            break;
    }

    cout << c;

    return 0;
}
