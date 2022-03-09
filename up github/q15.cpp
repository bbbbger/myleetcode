#include<vector>
using namespace std;
#include<algorithm>
#include<set>
#include<iostream>


//三数之和 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        if (nums.size() < 3) {
            return {};
        }

        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        
        for (int i = 0;i < nums.size();i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1, k = nums.size() - 1;j < k;) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    ans.push_back({ nums[i],nums[j],nums[k] });
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])j++;
                    while (j < k && nums[k] == nums[k + 1])k--;
                }
                else if (nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                }
                else {
                    k--;
                }
                
            }
        }
        return ans;

    }
};

void test() {
    vector<int> nums = { -5, 5, 0, 6, -2, -3, -3 };
    Solution s;
    vector<vector<int>> res=s.threeSum(nums);
    for (auto it = res.begin();it < res.end();it++) {
        for (int i = 0;i < it->size();i++) {
            cout << (*it)[i]<<"  ";
        }
        cout << endl;
    }
}
int main() {
    test();
    system("pause");
}