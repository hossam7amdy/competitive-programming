    /// WRONG ANSWER ///

#include<bits/stdc++.h>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
	freopen("out.txt", "wt", stdout);
#endif

    map<int, vector<pair<int, int>> > mp;
    mp[1] = {make_pair(0,0), make_pair(0,1), make_pair(0,2)};
    mp[2] = {make_pair(1,0), make_pair(1,1), make_pair(1,2)};
    mp[3] = {make_pair(2,0), make_pair(2,1), make_pair(2,2)};
    mp[4] = {make_pair(0,0), make_pair(1,0), make_pair(2,0)};
    mp[5] = {make_pair(0,1), make_pair(1,1), make_pair(2,1)};
    mp[6] = {make_pair(0,2), make_pair(1,2), make_pair(2,2)};
    mp[7] = {make_pair(0,0), make_pair(1,1), make_pair(2,2)};
    mp[8] = {make_pair(0,2), make_pair(1,1), make_pair(2,0)};

    const int N{3};
    string str;
    while(cin >> str){
        if(str == "end")
            break;

        /// How many x and o ?
        int count_x{}, count_o{};
        for(int i=0; i<(int)str.size(); ++i){
            count_x += (str[i] == 'X');
            count_o += (str[i] == 'O');
        }
        /// Find a winner?
        int x_won{}, o_won{};
        for(int i=1; i<=8; ++i){
            vector<pair<int, int>> check = mp[i];
            for(auto pair : check){
                // flatten trick
                int idx = pair.first * (int)check.size() + pair.second;
                x_won += (str[idx] == 'X');
                o_won += (str[idx] == 'O');
            }
            if(x_won == N || o_won == N)
                break;
            x_won = o_won = 0;
        }
        /// Final result

        if(o_won == N && count_x==count_o)
            cout << "valid\n";
        else if(x_won == N && !o_won && count_x-1==count_o)
            cout << "valid\n";
        else if(x_won!=N && o_won!=N && count_x-1==count_o && count_x+count_o == N*N)
            cout << "valid\n";
        else
            cout << "invalid\n";
    }

    return 0;
}
