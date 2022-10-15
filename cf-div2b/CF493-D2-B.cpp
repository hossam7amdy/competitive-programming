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


int main(){
    fast_IO();

    int n;
    cin >> n;

    int last_hit;
    ll sum = 0;
    vector<int> first, second;

    for(int i = 0; i < n; i++){
        cin >> last_hit;
        sum += last_hit;

        if(last_hit > 0)
            first.push_back(last_hit);
        else
            second.push_back(-last_hit);
    }


    if(sum > 0)
        cout << "first\n";
    else if(sum < 0)
        cout << "second\n";
    else{
        for(int i = 0; i < min((int)first.size(), (int)second.size()); ++i){
            if(first[i] != second[i]){
                if(first[i] > second[i])
                    cout << "first\n";
                else
                    cout << "second\n";
                return 0;
            }
        }

        if(last_hit > 0)
            cout << "first\n";
        else
            cout << "second\n";
    }

    return 0;
}
