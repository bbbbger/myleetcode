#include<vector>
using namespace std;
#include<algorithm>

//给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 1;  
        int last = nums[0];
        for (int i = 1;i < nums.size();i++) {
            if (nums[i] == last) {
                count++;
            }
            else if (count > (nums.size() >> 1)) {
                return last;
            }
            else {
                last = nums[i];
                count = 1;
            }
        }
    }
};

/*
 关于map
 map<key,value>m;
 通过key访问value： value=m[key]
 unordered_map<>m2   无序map  底层用哈希表实现       m2[key]key若不存在则向容器中插入一个新的键值对，value默认为0
*/