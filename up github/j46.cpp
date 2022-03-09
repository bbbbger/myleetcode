#include<string>
#include<cctype>
using namespace std;

class Solution {
public:
    int translateNum(int num) {
        string s(to_string(num));
        int len = s.size();
        int buf[11] = { 1 };
        buf[1] = (s[0] == '1' || (s[0] == '2' && ('0' <= s[1] && s[1] <= '5'))) ? 2 : 1;

        for (int i = 2;i < len;i++) {
            if (s[i - 1] == '1' || (s[i - 1] == '2' && '0' <= s[i] && s[i] <= '5')) {
                buf[i] = buf[i - 1] + buf[i - 2];

            }
            else    buf[i] = buf[i - 1];
        }
        return buf[len - 1];
    }
};