#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct group{
    int people{};
    int money{};
    int index{};

    bool operator < (const group &g){
        return money > g.money;
    }
};

struct table{
    int capacity{};
    int index{};

    bool operator < (const table &t){
        return capacity < t.capacity;
    }
};

bool canFit(const table &t, const group &g) {
	return t.capacity < g.people;
}

int main(){
    int n;
    cin >> n;
    vector<group> requests(n);
    for(int i = 0; i < n; ++i){
        cin >> requests[i].people >> requests[i].money;
        requests[i].index = i;
    }

    int k;
    cin >> k;
    vector<table> tables(k);
    for(int i = 0; i < k; i++){
        cin >> tables[i].capacity;
        tables[i].index = i;
    }

    sort(requests.begin(), requests.end());
    sort(tables.begin(), tables.end());

    int sum{};
    vector<pair<int, int>> ans;

    for(int i = 0; i < n; ++i){
        auto group = requests[i];
        auto iter = lower_bound(tables.begin(), tables.end(), group, canFit);

        if(iter == tables.end()) continue;

        sum += requests[i].money;
        ans.push_back(make_pair(requests[i].index, iter->index));

        tables.erase(iter);
    }

    cout << (int)ans.size() << " " << sum << "\n";
    for(const auto &pair : ans)
        cout << pair.first+1 << " " << pair.second+1 << "\n";

    return 0;
}
