#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void prefixSumArray(vector<int>& nums, vector<int>& pre) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            pre[i] = sum;
        }
    }
    int subarraySum(vector<int>& nums, int k) {
        vector<int> pre;
        pre.resize(nums.size());
        prefixSumArray(nums, pre);
        int total = 0;
        unordered_map<int, int> query;
        for (int i = 0; i < pre.size(); i++) {
            if (pre[i] == k) {
                total += 1;
            }
            if (query.find(pre[i] - k) != query.end()) {
                total += query[pre[i] - k];
            }
            query[pre[i]] += 1;
        }
        return total;
    }
};

vector<int> stringToVector(string s) {
    stringstream ss(s);
    string buf;
    vector<int> nums;
    while (ss >> buf) {
        nums.push_back(stoi(buf));
    }
    return nums;
}

int main() {
    string s;
    int k;
    cout << "input numbers: ";
    getline(cin, s);
    cout << "k: ";
    cin >> k;
    vector<int> nums = stringToVector(s);
    
    Solution sol;
    cout << sol.subarraySum(nums, k) << '\n';
}