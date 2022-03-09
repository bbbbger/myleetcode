using namespace std;
#include<vector>

//a1
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        for (int i = -1, j = 0;j<nums.size();j++) {
            if (nums[j] != 0) {
                i++;
                nums[i] = nums[j];
                if (i != j) {
                    nums[j] = 0;
                }
            }
        }
    }
};


