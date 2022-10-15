#include <iostream>
using namespace std;

///https://codeforces.com/contest/268/problem/A

int main()
{
	int n, arr[60], cnt = 0;

	cin >> n;


	for (int i = 0; i < n*2; i++)
		cin >> arr[i];



	for (int i = 0; i < n*2; i += 2) {

		for (int j = 1; j < n*2; j += 2) {
			cnt += (arr[i] == arr[j]);
		}
	}

	cout << cnt;

	return 0;
}
