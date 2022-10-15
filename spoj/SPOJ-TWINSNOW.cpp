#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> CELL;
#define x first
#define y second
#define ll long long

void fast_IO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
void readFile(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

struct hashFunction
{
  size_t operator()(const vector<int>
                    &myVector) const
  {
    std::hash<int> hasher;
    size_t answer = 0;

    for (int i : myVector)
    {
      answer ^= hasher(i) + 0x9e3779b9 +
                (answer << 6) + (answer >> 2);
    }
    return answer;
  }
};

int main(){
    fast_IO();

    int n;
    cin >> n;

    // we can use set or unorderd_set of vectors for fast comparison
    unordered_set<vector<int>, hashFunction> unorderedsetOfVectors; // O(1) lookup
    set<vector<int>> setOfVectors; // log(n) lookup

    for(int i = 0; i < n; ++i){
        vector<int> v(6);
        for(int i = 0; i < 6; ++i)
            cin >> v[i];

        sort(v.begin(), v.end());
        if(setOfVectors.count(v)){
            cout << "Twin snowflakes found.\n";
            return 0;
        }
        setOfVectors.insert(v);
    }

    cout << "No two snowflakes are alike.\n";
    return 0;
}
