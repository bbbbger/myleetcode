#include<vector>
#include<algorithm>

class Solution {
public:
    bool increasingTriplet(std::vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        int n = nums.size();
        std::vector<int>f(n, 1);
        for (int i = 1;i < n; i++) {           
            for (int j = 0;j < i;j++) {
                if (nums[j] < nums[i]) {
                    f[i] = f[i] > (f[j] + 1) ? f[i] : f[j]+1;
                }
           }
        }
        for (int n : f) {
            if (n >= 3) { return true; }           
        }
        return false;

        //---------------------------------------------------
        int first = INT_MAX, second = INT_MAX;
        for (int n : nums) {
            if (n <= first) {
                first = n;
            }
            else if (n <= second) {
                second = n;
            }
            else return true;
        }
        return false;
    }
};