#include <iostream>
using namespace std;

///https://codeforces.com/contest/281/problem/A

int main()
{
	string str;
	cin >> str;

	if (97 <= str[0] && str[0] <= 122)
		str[0] -= 32;

	cout << str;


	return 0;
}
