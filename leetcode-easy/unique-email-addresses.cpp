#include<bits/stdc++.h>
using namespace std;

int numUniqueEmails(vector<string>& emails) { // O(n * l)
    set<string> unique;

    for(auto email : emails){
        string domain = "";

        for(int i = email.size() - 1; i >= 0; --i){
            if(email[i] == '@'){
                domain = email.substr(i);
                break;
            }
        }


        string local = "";
        for(int i = 0; i < email.size(); ++i){
            if(email[i] == '.') continue;
            if(email[i] == '+' || email[i] == '@') break;

            local += email[i];
        }

        unique.insert(local + domain);
    }

    return unique.size();
}

int main() {

    return 0;
}
