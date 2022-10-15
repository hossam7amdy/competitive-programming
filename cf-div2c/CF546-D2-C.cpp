#include<iostream>
#include<deque>
#include<set>
using namespace std;

int main(){
    deque<int> p1, p2;

    int n, k1, k2;
    cin >> n >> k1;

    int val;
    while(k1--){
        cin >> val;
        p1.push_back(val);
    }

    cin >> k2;
    while(k2--){
        cin >> val;
        p2.push_back(val);
    }

    set<deque<int>> s1, s2;
    int turns = 0;
    while(!p1.empty() && !p2.empty()){
        int p1Val = p1.front(), p2Val = p2.front();
        p1.pop_front(), p2.pop_front();

        if(p1Val > p2Val)
            p1.push_back(p2Val), p1.push_back(p1Val);
        else
            p2.push_back(p1Val), p2.push_back(p2Val);

        if(s1.count(p1) && s2.count(p2)){
            cout << "-1\n";
            return 0;
        }
        s1.insert(p1), s2.insert(p2);
        ++turns;
    }

    int winner = 1;
    if(p1.empty())
        winner = 2;

    cout << turns << " " << winner << "\n";

    return 0;
}
