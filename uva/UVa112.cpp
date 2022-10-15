#include<bits/stdc++.h>
using namespace std;

void Run(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
	freopen("out.txt", "wt", stdout);
#endif
}

class BinaryTree{
private:
    int data{};
    BinaryTree* left{};
    BinaryTree* right{};
public:
    BinaryTree(const int& data):
        data(data){
    }
    bool Insert(const int &data, const string& str){
        BinaryTree* cur = this;
        for(int i=0; i<(int)str.size(); i++){
            if(str[i]=='L'){
                if(cur->left)
                    cur = cur->left;
                else if(!cur->left){
                    cur->left = new BinaryTree(data);
                    return (i == (int)str.size()-1);
                }
            }else if(str[i] == 'R'){
                if(cur->right)
                    cur = cur->right;
                else if(!cur->right){
                    cur->right = new BinaryTree(data);
                    return (i == (int)str.size()-1);
                }
            }
            else
                break;
        }
        return false;
    }
    void print_levelorder(){
        queue<BinaryTree*> nodes;
        nodes.push(this);

        while(!nodes.empty()){
            BinaryTree* cur = nodes.front();
            nodes.pop();

            if(cur->left)
                nodes.push(cur->left);
            if(cur->right)
                nodes.push(cur->right);

            cout << cur->data;
            if(!nodes.empty())
                cout << " ";
        }
        cout << "\n";
    }
};

int main(){
    Run();
    vector< pair<string,int> > v;

    string str;
    while(cin >> str){
        if(str == "()"){
            sort(v.begin(), v.end());
            if(v.front().first != ""){
                cout << "not complete\n";
                v.clear();
                continue;
            }
            BinaryTree tree(v.front().second);
            bool flag = true;
            for(int i=1; i<(int)v.size(); i++){
                if(!tree.Insert(v[i].second, v[i].first)){
                    cout << "not complete\n";
                    flag = false;
                    break;
                }
            }
            if(flag)
                tree.print_levelorder();
            v.clear();

        }else{
            int value = 0;
            string s;
            for(int i=0; i<(int)str.size(); i++){
                if(isdigit(str[i]))
                    value = (value * 10) + (str[i] - '0');
                else if(isalpha(str[i]))
                    s += str[i];
            }
            v.push_back(make_pair(s,value));
        }
    }

    return 0;
}
