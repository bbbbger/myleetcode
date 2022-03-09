#include<string>
using namespace std;
#include<unordered_map>

class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> hel;
        for (char c : s) {
            hel[c]++;
        }
        for (auto c : s) {
            if (hel[c] == 1) {
                return c;
            }
        }
        return ' ';
    }
};