#include<vector>
using namespace std;
#include<set>

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int min=nums[0],max=nums[0];
        int zero = 0;
        set<int> st;
        for (int& i : nums) {
            if (st.count(i) != 0 && i != 0)return false;
            else if (i == 0)zero++;
            else {
                min = min < i ? min : i;
                max = max > i ? max : i;
            }
            st.insert(i);
            
        }
        return max - min < 5;

    }
};