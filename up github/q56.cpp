using namespace std;
#include<vector>
#include<algorithm>
#include<iostream>
//合并区间
class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {return a[0] < b[0];});
        for (auto v : intervals) {
            cout << v[0] << " " << v[1] << endl;
        }
        vector<vector<int>> ans;
        ans.reserve(10000);
        
        for (int i = 1;i < intervals.size();i++) {
            if (intervals[i][0] <= intervals[i - 1][1]) {
                intervals[i][0] = intervals[i - 1][0];
                if (intervals[i - 1][1] > intervals[i][1]) {
                    intervals[i][1] = intervals[i - 1][1];
                }
                intervals[i - 1][0] = intervals[i - 1][1]+1;
            }
        }
        
        for (int i = 0; i < intervals.size();i++) {
            if (intervals[i][0] <= intervals[i][1]) {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};

int main() {

    vector<vector<int>> vv{ {1,4}, {0,0}};
    Solution s;
    vector<vector<int>>temp=s.merge(vv);
    for (auto v : temp) {
        cout << v[0] << " " << v[1] << endl;
    }
    system("pause");
}