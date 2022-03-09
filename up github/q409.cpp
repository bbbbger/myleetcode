#include<string>
using namespace std;
#include<unordered_map>

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int>mp;
        for (auto c : s) {
            mp[c]++;
        }
        int maxline = 0;
        int tag = 0;
        for (auto e : mp) {
            if (e.second % 2 == 1) {
                maxline++;
                tag = 1;
            }
        }
        return s.size() - maxline + tag;
    }
};