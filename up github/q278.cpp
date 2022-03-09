
class Solution {
public:
	bool isBadVersion(int mid) {};
	int firstBadVersion(int n) {
		int low = 1;
		int high = n;

		while (low < high) {
			int mid = (high - low) / 2 + low;
			if (isBadVersion(mid)) {
				high = mid;
			}
			else {
				low = mid + 1;
			}
		}
		return low;
	}
};