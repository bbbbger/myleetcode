#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    int sum = 0;
    int count;
    vector<int> num;
    vector<vector<int>> rec;
public:
    Solution(vector<vector<int>>& rects) {
        rec.assign(rects.begin(), rects.end());
        this->count = rects.size();
        for (int i = 0; i < count; i++) {
            num.push_back((rects[i][3] - rects[i][1] + 1) * (rects[i][2] - rects[i][0] + 1));
            sum += num[i];
        }
        srand((unsigned int)time(NULL));
    }

    vector<int> pick() {

        int rnd = rand() % sum + 1;
        cout << rnd << endl;
        int i = 0;
        for (; i < count; i++) {
            if ((rnd - num[i]) > 0) {
                rnd -= num[i];
                continue;
            }
            else break;
        }
        vector<int> res(2, 0);
        res[0] = (rnd - 1) / (rec[i][3] - rec[i][1] + 1) + rec[i][0];
        res[1] = (rnd - 1) % (rec[i][3] - rec[i][1] + 1) + rec[i][1];
        return res;
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
