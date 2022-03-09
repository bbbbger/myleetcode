#include<string>
using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        
        int len = s.size();
        int span = n % len;
        string cat(s, 0, span);
        string ans(s, span, len - span);
        ans.append(cat);
        return ans;
        
    }
};