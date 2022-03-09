#include<vector>
using namespace std;
#include<string>
#include<map>
#include<algorithm>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string>vv(strs);
        map<string, vector<int>>mp;
        int i = 0;
        for (auto v : vv) {
            sort(v.begin(), v.end());
            mp[v].push_back(i);
            i++;
        }
        vv.clear();
        vector<vector<string>>ans;
        
        for (auto iv : mp) {
            for (auto i : iv.second) {
                vv.push_back(strs[i]);
            }
            ans.push_back(vv);  
            vv.clear();
        }
        return ans;
    }
};