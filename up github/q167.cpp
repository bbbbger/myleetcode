using namespace std;
#include<vector>
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {


        for (int i = 0;i < numbers.size();i++) {
            int low = i + 1, high = numbers.size() - 1;
            while (low <= high) {
                int mid = (high - low) / 2 + low;
                if (target - numbers[mid] == numbers[i]) {
                    return { i + 1,mid + 1 };
                }
                else if (target - numbers[mid] > numbers[i]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }

        }
        return { -1,-1 };

    }
};

//a2Ë«Ö¸Õë
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0, j = numbers.size() - 1;i < j;) {
            if (target == numbers[i] + numbers[j]) {
                return { i + 1,j + 1 };
            }
            else if (target - numbers[i] < numbers[j]) {
                j--;
            }
            else {
                i++;
            }

        }
        return { -1,-1 };
    }
};