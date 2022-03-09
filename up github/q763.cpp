#include<string>
using namespace std;
#include<vector>
#include<map>


class Solution {
public:
    vector<int> partitionLabels(string s) {
        int len = s.size();
        map<char, pair<int, int>>mp;
        for (int i = 0;i < len;i++) {
            if (mp.find(s[i]) != mp.end()) {
                mp[s[i]].second = i;
            }
            else {
                mp[s[i]] = make_pair(i, i);
            }
        }
        vector<int>ans;
        int min=0, max=mp[0].second;
        for (auto c : s) {
            if (mp[c].first > max) {
                ans.push_back(max - min+1);
                min = mp[c].first;
                max = mp[c].second;
            }
            else if(mp[c].second>=max){
                max = mp[c].second;
            }
        }
        ans.push_back(max - min + 1);
        return ans;

    }
};