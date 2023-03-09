// https://leetcode.com/problems/construct-quad-tree/
#include<bits/stdc++.h>
using namespace std;

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    bool isSame(const vector<vector<int>> &grid, int r, int c, int sz){
        for(int i = r; i < r + sz; ++i)
            for(int j = c; j < c + sz; ++j)
                if(grid[i][j] != grid[r][c])
                    return false;
        return true;
    }

    Node* buildQuad(const vector<vector<int>>& grid, int r, int c, int sz){
        if(isSame(grid, r, c, sz))
            return new Node(grid[r][c], true);

        sz /= 2;
        auto topLeft = buildQuad(grid, r, c, sz);
        auto topRight = buildQuad(grid, r, c + sz, sz);
        auto bottomLeft = buildQuad(grid, r + sz, c, sz);
        auto bottomRight = buildQuad(grid, r + sz, c + sz, sz);
        return new Node(0, false, topLeft, topRight, bottomLeft, bottomRight);
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        return buildQuad(grid, 0, 0, grid.size());
    }
};

int main() {
    return 0;
}
