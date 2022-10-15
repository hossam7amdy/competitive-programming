#include<iostream>
#include <algorithm>
using namespace std;

///https://codeforces.com/contest/236/problem/A

int main() {

	string str;
	int sz = 1;

	cin >> str;

	sort(str.begin(), str.end());

	for(int i=1; i<str.size(); i++){
        if(str[i-1]!=str[i])
            sz++;
	}

	if (sz % 2 == 0)
		cout << "CHAT WITH HER!";
	else
		cout << "IGNORE HIM!";

	return 0;
}
