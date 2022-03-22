#include<iostream>
using namespace std;
#include<vector>
#include<string>

class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<int>> vv(m, vector<int>(n, 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vv[i][j] = mysum(i) + mysum(j);
            }
        }
        if (!m || !n)return 0;
        this->sizem = m;
        this->sizen = n;
        bfs(vv, 0, 0, k);
        return max;
    }
private:
    int sizem, sizen;
    int max = 0;
    int mysum(int num) {
        int sum = 0;
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    void bfs(vector<vector<int>>& vv, int i, int j, int k) {
        if (mysum(i) + mysum(j) > k || i < 0 || i >= sizem || j < 0 || j >= sizen || vv[i][j] == -1) {
            return;
        }
        max++;
        vv[i][j] = -1;
        bfs(vv, i + 1, j, k);
        bfs(vv, i, j + 1, k);             
    }
};













//class Solution {   
//public:
//    int movingCount(int m, int n, int k) {
//        vector<vector<int>> vv(m, vector<int>(n,1));
//        if (!m || !n || !k)return 0;
//        this->sizem = m;
//        this->sizen = n;
//        dfs(vv, 0, 0, k, 0);
//        return max;
//    }
//private:
//    int sizem, sizen;
//    int max = 0;
//    int mysum(int num) {
//        int sum = 0;
//        while (num != 0) {
//            sum += num % 10;
//            num /= 10;
//        }
//        return sum;
//    }
//    void dfs(vector<vector<int>> &vv, int i, int j, int k, int len) {
//        if (mysum(i) + mysum(j) > k || i < 0 || i >= sizem || j < 0 || j >= sizen ) {
//            this->max = this->max > len  ? this->max : len;
//            return;
//        }
//        if (vv[i][j] == -1)len--;
//        else {
//            vv[i][j] = -1;
//            dfs(vv, i + 1, j, k, len + 1);
//            dfs(vv, i, j + 1, k, len + 1);
//            dfs(vv, i - 1, j, k, len + 1);
//            dfs(vv, i, j - 1, k, len + 1);
//            vv[i][j] = 1;
//        }
//       
//    }
//};