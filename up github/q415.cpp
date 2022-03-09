#include<vector>
using namespace std;
#include<string>
#include<algorithm>

class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size() - 1;
        int n2 = num2.size() - 1;
        int add = 0;
        string ans = "";

        while (n1 >= 0 || n2 >= 0 || add > 0) {
            int x = n1 >= 0 ? num1[n1] - '0' : 0;
            int y = n2 >= 0 ? num2[n2] - '0' : 0;

            ans += (x + y + add) % 10 + '0';
            add = (x + y + add) / 10;
            n1--;
            n2--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};