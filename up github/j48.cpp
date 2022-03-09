#include<string>
using namespace std;
#include<unordered_map>
#include<vector>


class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();
        if (n == 0)return 0;
        int max = 1;
        int left = -1;
        vector<int> v(128, -1);

        for (int i = 0;i < n;i++) {
            if (v[s[i] - '\0'] < left) {
                max = std::max(max, i - left + 1);
            }
            else {
                left = v[s[i] - '\0'] + 1;
            }
            v[s[i] - '\0'] = i;
        }
        return max;
    }

};