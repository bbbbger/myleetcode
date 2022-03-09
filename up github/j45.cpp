#include<vector>
using namespace std;
#include<string>
#include<algorithm>
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> vnum;
        for (int& i : nums) {
            vnum.push_back(to_string(i));
        }
        sort(vnum.begin(), vnum.end(), [](string& x, string& y) {return x + y < y + x;});
        string ans;
        for (auto& str : vnum) {
            ans += str;
        }
        return ans;
    }
};