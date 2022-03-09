#include<string>
using namespace std;
#include<vector>
#include<unordered_map>

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        if (pattern.size() == 0 || s.size() == 0)return false;
        vector<string>v;
        int len = s.size();
        string temp;
        int space = 0;
        for (int i = 0;i < len;i++) {
            if (s[i] == ' ') {
                v.push_back(temp);
                temp.clear();
                space++;
            }
            else {
                temp += s[i];
            }
        }
        v.push_back(temp);
        if (pattern.size() != (space + 1))return false;
        unordered_map<char, string>mp;
        unordered_map<string, char>mp2;
        for (int i = 0;i < pattern.size();i++) {
            if (mp.find(pattern[i]) != mp.end()) {
                if (mp[pattern[i]] != v[i]) {
                    return false;
                }
            }
            else {
                mp[pattern[i]] = v[i];
            }
            if (mp2.find(v[i]) != mp2.end()) {
                if (mp2[v[i]] != pattern[i]) {
                    return false;
                }
            }
            else {
                mp2[v[i]] = pattern[i];
            }
        }
        return true;        
    }
};