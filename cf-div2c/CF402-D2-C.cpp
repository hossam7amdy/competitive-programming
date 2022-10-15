#include<iostream>
#include<vector>
using namespace std;

int main(){
    int Cases;
    cin >> Cases;
    while(Cases--){
        int n, p;
        cin >> n >> p;
        int edges = 2 * n + p;

        for(int i = 1; i <= n; ++i)
            for(int j = i + 1; j <= n && edges; ++j, --edges)
                cout << i << " " << j << "\n";
    }

    return 0;
}
