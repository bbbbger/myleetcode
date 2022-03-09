using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), [](vector<int> v1, auto v2) {return v1[1] < v2[1];});

        vector<int>maxleft(intervals[0]);
        int ans = 1;
        

        for (int i = 1;i < intervals.size();i++) {
            if (intervals[i][0] >= maxleft[1]) {
                ans++;
                maxleft[1] = intervals[i][1];
            }
        }
        return intervals.size() - ans;


    }
};