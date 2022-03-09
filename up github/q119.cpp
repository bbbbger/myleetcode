#include<vector>
using namespace std;
//O(n^2)
class Solution {
public:
    static int yhsj(int i,int n) {
        if (i == 0 || i == n) {
            return 1;
        }
        else {
            return Solution::yhsj(i - 1, n - 1) + Solution::yhsj(i, n - 1);
        }
    }
    vector<int> getRow(int rowIndex) {
        vector<int>row;
        for (int i = 0;i <= rowIndex;i++) {
            row.push_back(yhsj(i, rowIndex));
        }
        return row;
    }
};


//·¨¶þ  O(n)
class Solution2 {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>row;
        row[0] = 1;
        for (int i = 1;i <= rowIndex;i++) {
            row[i] = 1LL*row[i - 1] * (rowIndex - i + 1) / i;        //1LL  long long ·ÀÖ¹Òç³ö
        }
        return row;
    }
};