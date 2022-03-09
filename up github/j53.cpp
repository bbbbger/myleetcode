#include<vector>
using namespace std;
#include<unordered_map>

class Solution {
public:
    int search(vector<int>& nums, int target) {
        unordered_map<int, int> temp;
        for (int i : nums) {
            temp[i]++;
            
        }
        return temp[target];
    }
};


//53-¢ò

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        if (nums[0] != 0)return 0;
        for (int i = 1;i < n;i++) {
            if (nums[i] - nums[i - 1] != 1)return nums[i]-1;
        }
        return n;
    }
};