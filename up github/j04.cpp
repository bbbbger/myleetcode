#include<vector>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (!matrix.size())return false;
        for (auto v : matrix) {
            if (!v.size())break;
            if (v[0] > target) {
                return false;
            }
            else {
                for (int i = 0, j = v.size() - 1;i <= j;) {
                    int mid = (i + j) >> 1;
                    if (v[mid] == target) {
                        return true;
                    }
                    else if (v[mid] < target) {
                        i = mid + 1;
                    }
                    else {
                        j = mid - 1;
                    }
                }
            }
        }
        return false;
    }
};