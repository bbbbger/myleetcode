#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//ֻ����һ�ε�����

//��һ
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] != nums[i + 1] && i % 2 == 0) {               
                return nums[i];
            }
        }
        
        return nums.back();
        
    }
    
};

//����  ʹ���������   a^0=a,   a^a=0.