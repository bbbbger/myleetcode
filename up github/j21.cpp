#include<vector>
using namespace std;


class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0, j = 0;i < n;) {
            while (nums[j] % 2 != 0) {
                j++;
                if (j >= n)return nums;
            }
            while (nums[i] % 2 != 1) {
                i++;
                if (i >= n)return nums;
            }

            if (i > j) {
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
            else i++;

        }
        return nums;

    }
};