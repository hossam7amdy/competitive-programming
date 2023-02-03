// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) { // O(n)
        if(!root)
            return "()";

        string tree = "(" + to_string(root->val);
        tree += serialize(root->left);
        tree += serialize(root->right);
        return tree + ")";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) { // O(n^2)
        if(data == "()")
            return nullptr;

        int sz = data.size();
        int cntOpen = 0, cntClose = 0;
        string leftSubTree = "", rightSubTree = "";

        string num = strNum(data);
        for(int i = num.size() + 1; i < sz; ++i){
            cntOpen += data[i] == '(';
            cntClose += data[i] == ')';

            leftSubTree += data[i];
            if(cntOpen == cntClose){
                rightSubTree = data.substr(i+1, sz - i - 2);
                break;
            }
        }

        TreeNode* root = new TreeNode(stoi(num));
        root->left = deserialize(leftSubTree);
        root->right = deserialize(rightSubTree);
        return root;
    }
private:
    string strNum(string str){
        string num = "";
        for(int i = 1; i < str.size(); ++i){
            if(str[i] == '(') break;
            num += str[i];
        }

        return num;
    }
};

int main(){
    Codec().deserialize(Codec().serialize(new TreeNode(1)));

    return 0;
}
