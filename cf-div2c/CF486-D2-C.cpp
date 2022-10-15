#include <bits/stdc++.h>
using namespace std;

void fast_IO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

/*

1- find a not palindrome pairs
    - calculate best way to make two letters equal

2- shift p left for easy calculation

3- calculate left and right distance form p
    - which is the minimum distance to p (left or right)

4- multiply min_dist by 2 and add max_dist
    - answer = min_dist * 2 + max_dist + make_equal

    - Complexity O(n)

*/

int make_equal(char left, char right){
    int l = left - 'a', r = right - 'a';
    int mn = min(l,r);
    int mx = max(l,r);
    return min((mn + 25 + 1) - mx, mx-mn);
}

int main(){
    fast_IO();

    int n,cursor;
    string str;
    cin >> n >> cursor >> str;
    --cursor; // make zero-based
    if(cursor >= n/2) cursor = n - cursor - 1; // shift cursor to left

    int ans = 0, st = 0, en = n - 1, l = -1, r = -1;
    while(st < en){
        if(str[st] != str[en]){
            ans += make_equal(str[st], str[en]);

            if(st < cursor && l == -1)
                l = st;
            else if(st > cursor)
                r = st;
        }
        ++st, --en;
    }

    if(l == -1) l = cursor;
    if(r == -1) r = cursor;

    int mn_dist = min(cursor-l, r-cursor);
    int mx_dist = max(cursor-l, r-cursor);

    ans += (2 * mn_dist + mx_dist);

    cout << ans << "\n";

    return 0;
}
