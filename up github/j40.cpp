#include<vector>
using namespace std;
#include<algorithm>
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        arr.resize(k);
        return arr;
    }
};