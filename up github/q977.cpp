#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		vector<int>temp(nums.size());
		int i = 0, j = nums.size() - 1;
		for (int pos = nums.size() - 1;i <= j;pos--) {
			if (nums[i] * nums[i] <= nums[j] * nums[j]) {
				temp[pos] = nums[j] * nums[j];
				j--;
			}
			else {
				temp[pos] = nums[i] * nums[i];
				i++;
			}
		}
		return temp;

	}
};





int main() {

	/*unsigned int u;
	int i = -1;
	unsigned int j = (unsigned int)i;
	u = *(unsigned int*)(&i);
	cout << i << endl;
	cout << (i >> 1) << endl;
	cout << (i << 1) << endl;
	cout << j << endl;
	cout << (j << 1) << endl;
	cout << (j >> 1) << endl;
	cout << u << endl;
	cout << (u>>1) << endl;
	cout << (u<<1) << endl;*/

}