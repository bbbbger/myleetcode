#include<vector>
using namespace std;


//法一、超时
//class Solution {
//public:
//    vector<vector<int>> vv;
//    int maxValue(vector<vector<int>>& grid) {
//        vv = grid;
//
//        int m = grid.size()-1;
//        int n = grid.size()-1;
//
//        return f(m, n);
//
//
//
//    }
//    int f(int m, int n) {
//        if (!m && !n) {
//            return vv[0][0];
//        }
//        else if (m > 0 && n > 0) {
//            return vv[m][n] + max(f(m - 1, n), f(m, n - 1));
//        }
//        else if (m == 0)return vv[0][n] + f(0, n - 1);
//        else return vv[m][0] + f(m - 1, 0);
//    }
//};

//法二
class Solution {
public:

    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (!i && !j)continue;
                if (i == 0)grid[i][j] = grid[i][j] + grid[i][j - 1];
                else if (j == 0)grid[i][j] = grid[i][j] + grid[i - 1][j];
                else grid[i][j] = grid[i][j] + max(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }

};