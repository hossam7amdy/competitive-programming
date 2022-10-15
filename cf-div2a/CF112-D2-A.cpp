#include<iostream>
#include<string>
#include <stdio.h>
#include <ctype.h>
using namespace std;

///https://codeforces.com/contest/112/problem/A

int main() {

	string str1, str2;

	cin >> str1 >> str2;

	int flag = 0;

	for (int i = 0; i < str2.size(); i++) {
		char ch1, ch2;
		ch1 = tolower(str1[i]);
		ch2 = tolower(str2[i]);

		if (ch1 > ch2) {
			flag = 1;
			break;
		}
		else if (ch1 < ch2) {
			flag = -1;
			break;
		}
	}

	cout << flag;

	return 0;
}
