#include<vector>
using namespace std;

class Solution {
private:
    vector<int>edge;
public:
    int direction(int& i, int& j, int dir, vector<int>& edg) {
        if (i == edg[0] && j == edg[2] && dir == 3) {
            edg[2] += 1;
            j++;
            return 0;  //右
        }
        else if (i == edg[0] && j == edg[3] && dir == 0) {
            edg[0] += 1;
            i++;
            return 1;  //下
        }
        else if (i == edg[1] && j == edg[3] && dir == 1) {
            edg[3] -= 1;
            j--;
            return 2;  //左
        }
        else if (i == edg[1] && j == edg[2] && dir == 2) {
            edg[1] -= 1;
            i--;
            return 3;  //上
        }
        else {
            return dir;  //不变
        }
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n, vector<int>(n));

        edge = { 0,n - 1,0,n - 1 };
        int dir = 0;
        int nextdir = 0;
        for (int i = 1, j = 0, k = 0;i <= n * n;i++) {         //坐标（j，k）  
            matrix[j][k] = i;
            nextdir = direction(j, k, dir, edge);
            if (dir != nextdir) {
                dir = nextdir;
            }
            else {
                if (dir == 0) {
                    k++;
                }
                else if (dir == 1) {
                    j++;
                }
                else if (dir == 2) {
                    k--;
                }
                else {
                    j--;
                }
            }
        }
        return matrix;
    }
};