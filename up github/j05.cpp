#include<string>
using namespace std;
class Solution {
public:
    string replaceSpace(string s) {
        for (int i = s.size()-1;i >= 0; i--) {
            if (s[i] == ' ') {
                s.replace(i, 1, "%20");
            }
        }
        return s;
    }
};