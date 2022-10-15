#include <iostream>
using namespace std;

int main()
{
    int n,cnt=0;
    string s;

    cin >> n >> s;

    for(int i=1; i<n; i++){
        if(s[i-1]==s[i])
            cnt++;
    }

    cout << cnt;

    return 0;
}
