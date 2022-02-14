#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    map<char, int> alph;
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        int l = 0, r = 0;
        while (r < s.size()) {
            map<char, int>::iterator it = alph.find(s[r]);
            if (it == alph.end() || alph[s[r]] == -1) { // not found
                alph[s[r]] = r;
                int len = r - l + 1;
                if (len > maxlen) {
                    maxlen = len;
                }
            } else {
                for ( ; l <= alph[s[r]]; l++) {
                    alph[s[l]] = -1;
                }
                alph[s[r]] = r;
            }
            r++;
        }
        return maxlen;
    }
};

int main() {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << '\n';
}