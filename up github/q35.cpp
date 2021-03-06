#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();

        while (l < r) {
            int mid = (r - l) / 2 + l;
            if (nums[mid] == target) {
                return mid;
            }
            else if (target < nums[mid]) {
                r = mid;
            }
            else {
                l = mid + 1;
            }

        }
        return r;

    }
};