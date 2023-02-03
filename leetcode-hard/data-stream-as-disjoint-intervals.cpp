// https://leetcode.com/problems/data-stream-as-disjoint-intervals/
#include<bits/stdc++.h>
using namespace std;

/*
#Approach: Ordered Set & Binary Search

#Complexity
    - Time: O(n)
    - Space: O(n)
*/

class SummaryRanges {
public:
    SummaryRanges() {}

    void addNum(int value) { // O(logn)
        int sz = stream.size();
        stream.insert(value);

        if(sz != stream.size())
            mergeInterval({value, value});
    }

    vector<vector<int>> getIntervals() { // O(1)
        return intervals;
    }

private:
    set<int> stream;
    vector<vector<int>> intervals;

    void mergeInterval(const vector<int> &interval){ // O(n)
        int value = interval[0];

        // new at end
        if(intervals.empty() || intervals.back()[1] < value - 1){
            intervals.push_back(interval);
        // merge with end
        }else if(intervals.back()[1] == value - 1){
            intervals.back()[1] = value;
        }
        // new at front
        else if(intervals.front()[0] > value + 1){
            intervals.insert(intervals.begin(), interval);
        // merge with front
        }else if(intervals.front()[0] == value + 1){
            intervals.front()[0] = value;
        }else{
            // find right location & merge
            auto iter = lower_bound(intervals.begin(), intervals.end(), interval);
            int idx = iter - intervals.begin();

            if(idx == 0){
                intervals[idx][0] = value;
            }
            // merge left with right
            else if(intervals[idx - 1][1] == value - 1 && intervals[idx][0] == value + 1){
                intervals[idx - 1][1] = intervals[idx][1];
                intervals.erase(iter);
            }
            // merge with left
            else if(intervals[idx - 1][1] == value - 1){
                intervals[idx - 1][1] = value;
            }
            // merge with right
            else if(intervals[idx][0] == value + 1){
                intervals[idx][0] = value;
            }
            // insert as new
            else{
                intervals.insert(intervals.begin() + idx, interval);
            }
        }
    }
};

int main() {

	return 0;
}
