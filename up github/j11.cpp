using namespace std;
#include<vector>

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int n = numbers.size();
        
        for (int i = 1;i < n;i++) {
            if (numbers[i] < numbers[i - 1])return numbers[i];
        }
        return numbers[0];
    }
};