#include<vector>
using namespace std;
#include<unordered_map>

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> temp;
        for (int i : nums) {
            if (temp.find(i) != temp.end()) {
                return i;
            }
            else {
                temp[i] += 1;
            }
        }
        return -1;
    }
};