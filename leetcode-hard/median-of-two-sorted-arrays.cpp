#include<bits/stdc++.h>
using namespace std;

/*

#Intuition: median of a list / formula
    [1,2,3] => 2
    [1,2,3,4] => (2+3)/2 = 2.5

#Complexity
    - Time: O((n+m)/2)
    - Space: O(1)
*/

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int sz1 = (int)nums1.size(), sz2 = (int)nums2.size();
    int mid = (sz1 + sz2) / 2;
    bool isEven = (sz1 + sz2) % 2 == 0;
    if(isEven) --mid;

    double median = 0;
    int idx1 = 0, idx2 = 0;
    while(idx1 + idx2 <= mid){
        if(idx2 == sz2 || idx1 < sz1 && nums1[idx1] < nums2[idx2])
            median = nums1[idx1++];
        else
            median = nums2[idx2++];
    }

    if(!isEven) return median;

    if(idx2 == sz2 || idx1 < sz1 && nums1[idx1] < nums2[idx2])
        median += nums1[idx1];
    else
        median += nums2[idx2];

    return median / 2;
}

int main(){

    return 0;
}
