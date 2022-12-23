
#include<bits/stdc++.h>
using namespace std;

/*
# Approach 1
    - flatten matrix + Binary Search

# Approach 2: Binary Search
    - BS in rows then in cols

# Complexity
    - Time: O(logn * logm)
    - Space: O(1)
*/

bool searchMatrix_(vector<vector<int>>& matrix, int target) {
    // flatten matrix
    int st = 0;
    int colLen = matrix[0].size();
    int rowLen = matrix.size();
    int en = colLen * rowLen - 1;

    // normal binary search
    while(st <= en){
        int mid = st + (en - st) / 2;

        int row = mid / colLen;
        int col = mid % colLen;

        if(matrix[row][col] == target)
            return true;

        if(matrix[row][col] < target)
            st = mid + 1;
        else
            en = mid - 1;
    }

    return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int st = 0, en = (int)matrix.size() - 1;

    // search rows
    int row = -1;
    while(st <= en){
        int mid = st + (en - st) / 2;

        if(matrix[mid].back() < target)
            st = mid + 1;
        else if(matrix[mid].front() > target)
            en = mid - 1;
        else{
            row = mid;
            break;
        }

        if(row == -1)
            return false;

        // search columns
        st = 0, en = matrix[row].size() - 1;
        while(st <= en){
            int mid = st + (en - st) / 2;

            if(matrix[row][mid] < target)
                st = mid + 1;
            else if(matrix[row][mid] > target)
                en = mid - 1;
            else
                return true;
        }

        return false;
    }
}

int main(){

    return 0;
}
