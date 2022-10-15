///HW: Write a simple code to implement string permutation using Backtracking. String abcd has 24 permutation.

#include<iostream>
#include<vector>
using namespace std;

int counter = 0, visitedCount = 0, total = 0;
vector<string> result;
vector<int> indices;
void countPermutaion(const string &str, int node, vector<bool> &visited){
    if(visitedCount + 1 == (int)str.length()){
        ++counter;

        string s;
        for(int idx : indices)
            s += str[idx];
        s += str[node];
        result.push_back(s);
        return;
    }

    if(visited[node])
        return;

    // do
    visited[node] = true;
    indices.push_back(node);
    ++visitedCount;
    ++total;

    // recurse
    for(int i = 0; i < (int)str.length(); ++i){
        if(i != node && !visited[i])
            countPermutaion(str, i, visited);
    }

    // undo
    visited[node] = false;
    indices.pop_back();
    --visitedCount;
}


int main(){

    string str;
    cin >> str;
    vector<bool> visited((int)str.size(),0);

    for(int i = 0; i < (int)str.size(); ++i)
        countPermutaion(str, i, visited);

    cout << counter << "\n";
    for(string perm : result)
        cout << perm << " ";

    cout << "\nTotal calls: " << total << "\n";

    return 0;
}
