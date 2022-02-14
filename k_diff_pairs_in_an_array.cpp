#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<int> query;
        set<pair<int, int> > pool;
        for (int i = 0; i < nums.size(); i++) {
            if (query.find(nums[i] - k) != query.end()) {
                pool.insert(make_pair(nums[i] - k, nums[i]));
            }
            if (query.find(nums[i] + k) != query.end() && k != 0) {
                pool.insert(make_pair(nums[i], nums[i] + k));
            }
            query.insert(nums[i]);
        }
        return pool.size();
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
    cout << "numbers: ";
    getline(cin, s);
    cout << "k: ";
    cin >> k;    
    vector<int> nums = stringToVector(s);

    Solution sol;
    cout << sol.findPairs(nums, k) << '\n';
}