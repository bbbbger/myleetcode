#include<vector>
using namespace std;
#include<iostream>
class Solution {
public:
    void sortColors(vector<int>& nums) {
        //sort(nums.begin(),nums.end());

        int i = 0, j = 0, k = 0;

        for (int m = 0;m < nums.size();m++) {
            if (nums[m] == 0)i++;
            else if (nums[m] == 1)j++;
            else k++;
        }
        vector<int>temp(i);
        while (j--)temp.push_back(1);
        while (k--)temp.push_back(2);
        nums.swap(temp);

    }
};

int main() {
    vector<int>v{ 0,2,0,1,0,2,1,0,2,1,1,0,2,0,1 };
    Solution sc;
    sc.sortColors(v);
    for (auto e : v)cout << e << " ";
    cout << endl;
    system("pause");

}