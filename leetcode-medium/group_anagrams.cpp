#include<bits/stdc++.h>
using namespace std;

/*
    Given an array of strings strs, group the anagrams together.
    Ex. strs = ["eat","tea","tan","ate","nat","bat"] -> [["bat"],["nat","tan"],["ate","eat","tea"]]

    SOLUTIONS:
    - hash map + sort: for each element sort and pair it with the original -> O(n * l) time & O(n * l) space
*/

vector<vector<string>> groupAnagrams_(const vector<string>& strs) {
    unordered_map<string, vector<string>> groups;

    for(auto str : strs){
        string temp = str;
        sort(temp.begin(), temp.end());

        groups[temp].push_back(str);
    }

    vector<vector<string>> result;
    for(auto pair : groups)
        result.push_back(pair.second);

    return result;
}

/* ========================== */

string getKey(string str){
    int count[26] = {0};
    for(auto ch : str)
        count[ch - 'a']++;

    string key = "";
    for(int i = 0; i < 26; ++i)
        while(count[i])
            key += (char) i + 'a';

    return key;
}

vector<vector<string>> groupAnagrams(const vector<string>& strs) {
    unordered_map<string, vector<string>> groups;

    for(auto str : strs){
        string key = getKey(str);

        groups[key].push_back(str);
    }

    vector<vector<string>> result;
    for(auto pair : groups)
        result.push_back(pair.second);

    return result;
}

int main() {
    vector<vector<string>> result;

    result = groupAnagrams({"eat","tea","tan","ate","nat","bat"});

    for(auto group : result){
        for(auto item : group)
            cout << item << " ";
        cout << "\n";
    }

    return 0;
}
