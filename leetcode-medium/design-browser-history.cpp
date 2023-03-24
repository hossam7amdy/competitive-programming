// https://leetcode.com/problems/design-browser-history/
#include<bits/stdc++.h>
using namespace std;

/*
#Complexity
    - Time: O(n)
    - Space: O(n)
*/

class BrowserHistory {
    int curUrl {};
    int lastUrl {};
    vector<string> history;

public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
    }

    void visit(string url) {
        ++curUrl;
        if(curUrl < history.size()){
            history[curUrl] = url;
        }else{
            history.push_back(url);
        }

        lastUrl = curUrl;
    }

    string back(int steps) {
        curUrl = max(curUrl - steps, 0);
        return history[curUrl];
    }

    string forward(int steps) {
        curUrl = min(curUrl + steps, lastUrl);
        return history[curUrl];
    }
};

int main(){

    return 0;
}

