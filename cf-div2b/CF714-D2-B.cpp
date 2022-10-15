#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;


int main(){
    int n;
    cin >> n;
    set<int> st;

    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        st.insert(val);
    }

    int sz = st.size();
    if(sz<3)
        cout << "YES";
    else if(sz>3)
        cout << "NO";
    else{
        vector<int> v(sz);
        v[0] = *(st.begin());
        v[1] = *(++st.begin());
        v[2] = *(--st.end());

        if(v[2] - v[1] == v[1]-v[0])
            cout << "YES";
        else
            cout << "NO";
    }


    return 0;
}
