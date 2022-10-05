#include<iostream>
#include<queue>

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string s) {

        vector<string> ans;
        ans.push_back(s);
        for (int i = 0; i < s.size(); i++)
        {
            int count = ans.size();
            for (int j = 0; j < count; j++)
            {
                if ('a' <= ans.at(j).at(i) && ans.at(j).at(i) <= 'z'
                    || 'A' <= ans.at(j).at(i) && ans.at(j).at(i) <= 'Z')
                {
                    if (ans.at(j).at(i) <= 'Z')
                    {
                        ans.push_back(ans.at(j));
                        ans.at(j).at(i) = ans.at(j).at(i) - 'A' + 'a';
                    }
                    else
                    {
                        ans.push_back(ans.at(j));
                        ans.at(j).at(i) = ans.at(j).at(i) - 'a' + 'A';
                    };
                }
            }

        }
        return ans;
    }
};