#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/// https://codeforces.com/contest/490/problem/A


int main(){
    int num, w;
    vector<int> t1, t2, t3;

    cin >> num;
    for(int i=1; i<=num; i++){

        cin >> w;

        if(w==1)
            t1.push_back(i);
        else if(w==2)
            t2.push_back(i);
        else if(w==3)
            t3.push_back(i);
    }

    w = min((int)t1.size(), (int)t2.size());
    w = min(w, (int)t3.size());

    if(w==0){
        cout << w;
        return 0;
    }

    cout << w << "\n";

    for(int i=0; i<w; i++)
        cout << t1[i] << " " << t2[i] << " " << t3[i] << "\n";

    return 0;
}
