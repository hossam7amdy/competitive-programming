#include <iostream>
#include <deque>
using namespace std;

///https://codeforces.com/contest/381/problem/A

int main()
{
    deque<int> game;
    int n,num,S=0,D=0;

    cin >> n;
    while(n--){
        cin >> num;
        game.push_back(num);
    }

    while(!game.empty()){
        if(game.front()>game.back())
            S+=game.front(), game.pop_front();
        else
            S+=game.back(), game.pop_back();

        if(game.empty())
            break;


        if(game.front()>game.back())
            D+=game.front(), game.pop_front();
        else
            D+=game.back(), game.pop_back();
    }

    cout << S << " " << D;

    return 0;
}
