// https://leetcode.com/problems/simplify-path/
#include<bits/stdc++.h>
using namespace std;

string simplifyPath(string path) {
    path.push_back('/');
    int l = 0, dots = 0;
    string cur = "/", res = "";

    for(int r = 1; r < path.size(); ++r){
        if(path[r] == '/'){
            if(cur.back() == '/') {
                l = r;
                continue;
            };
            int subLen = r - l - 1;
            if(subLen == 2 && dots == 2){
                while(res.size() && res.back() != '/')
                    res.pop_back();
                if(res.size())
                    res.pop_back();
            }else if(subLen > dots || dots > 2)
                res += cur;
            l = r;
            cur = "";
            dots = 0;
        }

        cur += path[r];
        dots += (path[r] == '.');
    }

    res += cur;
    if(res.size() > 1 && res.back() == '/')
        res.pop_back();

    return res;
}

int main(){

    return 0;
}
