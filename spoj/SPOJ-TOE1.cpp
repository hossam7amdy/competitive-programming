#include<bits/stdc++.h>
using namespace std;

const int sz = 3;
vector<string> v(sz);
bool won(vector<pair<int,int>> pairs, const char &ch){
    for(int i=0; i<sz; ++i){
        pair<int, int> p {pairs[i]};
        if(v[p.first][p.second]!=ch)
            return false;
    }
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	//freopen("c.in", "rt", stdin);
	//freopen(".txt", "wt", stdout);
#endif

    map<int, vector<pair<int,int>> > mp;
    mp[1] = {make_pair(0,0),make_pair(1,1),make_pair(2,2)};
    mp[2] = {make_pair(0,0),make_pair(1,0),make_pair(2,0)};
    mp[3] = {make_pair(0,1),make_pair(1,1),make_pair(2,1)};
    mp[4] = {make_pair(0,2),make_pair(1,2),make_pair(2,2)};
    mp[5] = {make_pair(0,2),make_pair(1,1),make_pair(2,0)};
    mp[6] = {make_pair(0,0),make_pair(0,1),make_pair(0,2)};
    mp[7] = {make_pair(1,0),make_pair(1,1),make_pair(1,2)};
    mp[8] = {make_pair(2,0),make_pair(2,1),make_pair(2,2)};

    int n;
    cin >> n;
    while(n--){

        for(int i=0; i<sz; ++i)
            cin >> v[i];

        int X=0, O=0;
        for(int r=0; r<sz; ++r){
            for(int c=0; c<sz; ++c){
                X+=(v[r][c]=='X');
                O+=(v[r][c]=='O');
            }
        }

        bool x_won = false;
        bool o_won = false;
        for(auto &pair : mp){
            x_won = (x_won || won(pair.second,'X'));
            o_won = (o_won || won(pair.second,'O'));
        }

        if(x_won && !o_won && X-1 == O)
            cout << "yes\n";
        else if(o_won && !x_won && X == O)
            cout << "yes\n";
        else if(!x_won && !o_won && (X-1 == O || X == O))
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}
