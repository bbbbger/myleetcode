#include<string>
#include<iostream>
using namespace std;
//Î´Í¨¹ý
//"ebcbbececabbace c b b c be"
class Solution {
public:
    bool validPalindrome(string s) {
        int num = 0;
        int flag=1;
        int choose = 0;
        for (int left = 0, right = s.size() - 1;left < right;) {
            cout << num++ << endl;
            if (s[left] == s[right]) {
                left++;
                right--;
            }
            else if(flag){   

                if (s[left] == s[right - 1] && s[left + 1] == s[right]) {
                    choose++;
                    if (choose == 1) {

                        right -= 2;
                        left++;
                        flag--;
                    }
                    else if (choose == 2) {

                        cout << left << "  " << right << endl;
                        left += 2;
                        right--;
                        flag--;
                    }
                }

                else if (s[left] == s[right - 1]) {
                    
                    right-=2;
                    left++;
                    flag--;
                } 

                else if (s[left + 1] == s[right]) {
                    
                    cout << left << "  " << right << endl;
                    left += 2;
                    right--;
                    flag--;
                }             
            }

            else {
                if (choose == 1) {
                    left = 0;
                    right = s.size() - 1;
                    flag = 1;
                }
                else {
                    return false;
                }                 
            }
         

        return true;
    }
};

    int main() {
        string s = "ebcbb e cecabbace c bbcbe";
        Solution an;
        if (an.validPalindrome(s)) {
            cout << "true" << endl;
        }
        else {
            cout << "false" << endl;
        }
    };