#include<bits/stdc++.h>
using namespace std;

/*
#Complexity
    - Time: O(nlogn) => n operations AND logn per get operation
    - Space: O(n)
*/

// Map
class TimeMap_v1 {
    map<pair<int,string>,string> store;
    int maxTimestamp;
public:
    TimeMap_v1() {
        maxTimestamp = 0;
    }

    void set(string key, string value, int timestamp) {
        store[{timestamp, key}] = value;
        maxTimestamp = max(timestamp, maxTimestamp);
    }

    string get(string key, int timestamp) {
        timestamp = min(timestamp, maxTimestamp);

        while(timestamp){
            if(store.count({timestamp, key}))
                return store[{timestamp,key}];
            --timestamp;
        }
        return "";
    }
};

// Hash Map
class TimeMap_v2 {
    // will use custom hashing function to store `key + timestamp` as unique key
    unordered_map<string,string> store;
    int maxTimestamp; // prevent huge unnecessary `timestamp`

    string hash(string str, int num){
        while(num){
            int digit = num % 10;
            str += (digit + '0');

            num /= 10;
        }

        return str;
    }

public:
    TimeMap_v2() {
        maxTimestamp = 0;
    }

    void set(string key, string value, int timestamp) { // O(1)
        store[hash(key, timestamp)] = value;
        maxTimestamp = max(timestamp, maxTimestamp);
    }

    string get(string key, int timestamp) { // O(n)
        timestamp = min(timestamp, maxTimestamp);

        while(timestamp){
            string nKey = hash(key, timestamp);
            if(store.count(nKey))
                return store[nKey];
            --timestamp;
        }
        return "";
    }
};

// Binary Search
class TimeMap {
private:
    // same key can have multiple timestamps `unique and in increasing order`
    // no need for complicated hashing, store them in a vector and binary search on them
    unordered_map<string, vector<pair<int,string>> > store;

    string search(const vector<pair<int,string>> &values, int timestamp){
        string res = "";
        int st = 0, en = (int)values.size() - 1;

        while(st <= en){
            int mid = st + (en - st) / 2;

            if(values[mid].first < timestamp)
                st = mid + 1, res = values[mid].second;
            else if(values[mid].first > timestamp)
                en = mid - 1;
            else
                return values[mid].second;
        }

        return res;
    }

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) { // O(1)
        store[key].push_back({timestamp,value});
    }

    string get(string key, int timestamp) { // O(logn)
        const auto exist = store.find(key);
        if(exist == store.end())
            return "";

        return search(exist->second, timestamp);
    }
};

int main(){

    return 0;
}
