#include<vector>
using namespace std;

/*
240 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。

*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x = matrix.size();
        int y = matrix.front().size();
              
        for (int i = 0, j = x, m = 0, n = y;i <= j && m <= n;) {  
            int ax = j >> 1, ay = n >> 1;
            if (matrix[ax][ay] == target) {
                return true;
            }
            if (matrix[ax][ay] < target) {
                if (target >= matrix[j][ay]) {
                    m = ay;
                }
                if (target >= matrix[ax][n]) {
                    i=ax;
                }
            }
            else {
                if (target <= matrix[i][ay]) {
                    n = ay;
                }
                if (target <= matrix[ax][m]) {
                    j = ax;
                }
            }
        }
        return  false;
    }
};