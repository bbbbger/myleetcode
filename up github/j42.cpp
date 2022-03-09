
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)return 0;
        int lastsum[100000];
        lastsum[0] = nums[0];
        int min = 0<nums[0]?0:nums[0];
        int max = nums[0];
        for (int i = 1;i < n;i++) {
            lastsum[i] = lastsum[i - 1] + nums[i];
            max = max > lastsum[i] - min ? max : lastsum[i] - min;
            min = min < lastsum[i] ? min : lastsum[i];
        }
        return max;
    }
};