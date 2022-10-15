// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1558
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 60 + 1;
int memory[MAX][MAX];

string text;
ll countPalindrome(int left, int right){ // O(n^2)
    if(left == right)
        return 1;

    if(left + 1 == right)                       // 2 letters
        return 2 + (text[left] == text[right]); // 2 => AB | 3 => AA

    auto &ret = memory[left][right];
    if(ret != -1)
        return ret;

    ret = 0;
    if(text[left] == text[right])
        // +1 for the whole string with removed body
        ret += 1 + countPalindrome(left + 1, right - 1);

    ret += countPalindrome(left, right - 1);
    ret += countPalindrome(left + 1, right);
    // remove duplication of (left+1, right), (left, right-1)
    ret -= countPalindrome(left + 1, right - 1);

    return ret;
}

int main(){
    int n;
    cin >> n;

    while(n--){
        cin >> text;

        memset(memory, -1, sizeof(memory));
        cout << countPalindrome(0, (int)text.size() - 1) << "\n";
    }

    return 0;
}

/*
3
BAOBAB
AAAA
ABA
*/
