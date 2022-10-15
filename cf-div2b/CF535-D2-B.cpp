#include<bits/stdc++.h>
using namespace std;

long long MAX{1000000000};
vector<long long> lucky_numbers;

void push_lucky(long long num){
    if(num > MAX)
        return;

    if(num)
        lucky_numbers.push_back(num);

    push_lucky(num * 10 + 4);
    push_lucky(num * 10 + 7);
}

void solve(){
    push_lucky(0);

    sort(lucky_numbers.begin(), lucky_numbers.end());

    int num;
    cin >> num;

    for(int i=0; i<MAX; i++){
        if(lucky_numbers[i] == num){
            cout << i+1 << endl;
            return;
        }
    }
}

int main(){
    // solve(); // another way using recursion

    string str;
    cin >> str;

    int ans = 0, sum = 1, sz = (int)str.size();
    for(int i=0, j=sz-1; i<sz; i++, j--){
        ans += pow(2,i);

        if(str[j] == '7')
            ans += sum;
        sum *= 2;
    }

    cout << ans << endl;


    return 0;
}
