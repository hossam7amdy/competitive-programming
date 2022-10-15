#include<iostream>
#include<vector>
using namespace std;

/// https://codeforces.com/contest/66/problem/B

int main(){
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i=0; i<n; i++)
        cin >> v[i];

    //Idea: increasing and decreasing
    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        int temp = 1;

        for(int j=i; j<n-1; j++)
        {
            if(v[j]>=v[j+1])
                temp++;
            else
                break;
        }

        for(int k=i; k>0; k--)
        {
            if(v[k]>=v[k-1])
                temp++;
            else
                break;
        }

        if(temp>cnt)
            cnt = temp;
    }
    cout << cnt;

    return 0;
}
