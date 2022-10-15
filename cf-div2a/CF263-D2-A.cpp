#include<iostream>
#include<cmath>
using namespace std;

///https://codeforces.com/contest/263/problem/A

int main(){
    int ROWS = 5;
    int COLS = 5;
    int r,c;

    int matrix;

    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            cin >> matrix;
            if(matrix==1)
                r=i+1, c=j+1; //one based
        }
    }

    cout << abs(3-r)+abs(3-c);

    return 0;
}
