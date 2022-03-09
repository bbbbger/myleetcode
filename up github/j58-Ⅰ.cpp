
#include<string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        revs(s, 0, n);
        string ans;
        for (int i = 0;i < n;) {
            while (s[i] == ' '&&i<n)i++;
            int j = i;
            while (s[j] != ' '&&j<n)j++;
            revs(s, i, j);
            ans.append(s, i, j-i+1);
            ans += ' ';
            i = j;
        }
        return ans;
    }
    void revs(string& s,int left,int right) {
        for (int i = left, j = right; i < j;i++, j--) {
            swap(s[i], s[j]);
        }
    }
};