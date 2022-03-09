#include<vector>
using namespace std;
#include<numeric>
#include<unordered_map>

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int ans = 0;
        unordered_map<int,int>mp;
        mp[0] = 1;
        int pre = 0;
        for (int n : nums) {
            pre += n;
            if (mp.find(pre - k) != mp.end()) {
                ans+=mp[pre-k];
            }
            mp[pre]++;
        }
        return ans;

    }
};