#include<vector>
using namespace std;
//��ת����
//�������顢��ת���顢��״�滻gcd

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        int time = k % len;
        vector<int>temp(len);
        for (int i = 0;i < len;i++) {
            temp[(i+k)%len]=nums[i];
        }
        nums.assign(temp.begin(), temp.end());
       /* for (int i = 0;i < len;i++) {
            nums[i] = temp[i];
        }*/
    }
};