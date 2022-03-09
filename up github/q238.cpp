#include<vector>

class Solution {
public:
	std::vector<int> productExceptSelf(std::vector<int>& nums) {
		int n = nums.size();
		std::vector<int> ans(n,1);
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				if (j == i) { continue; }
				ans[i] *= nums[j];
			}
		}
		return ans;		
	}
};

class Solution2 {
public:
	std::vector<int> productExceptSelf(std::vector<int>& nums) {
		int n = nums.size();
		std::vector<int>L(n);
		std::vector<int>R(n);
		L[0] = R[n-1] = 1;
		for (int i = 1;i < n;i++) {
			L[i] = L[i - 1] * nums[i - 1];
			R[n - i - 1] = R[n - i] * nums[n - i];
		}
		for (int i = 0;i < n;i++) {
			nums[i] = L[i] * R[i];
		}
		return nums;
	}
};