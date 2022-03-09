#include<vector>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        if (n == 0)return 0;
        int min = prices[0];
        int max = 0;
        for (int i = 0;i < n;i++) {
            max = (prices[i] - min) >= max ? (prices[i] - min) : max;
            min = prices[i] <= min ? prices[i] : min;
        }
        return max;

    }
};