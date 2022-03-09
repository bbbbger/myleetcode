#include<iostream>
using namespace std;
#include<vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    
};
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        ListNode* temp=head;
        while (temp != NULL) {
            ans.push_back(temp->val);
            temp = temp->next;
        }
        for (int i = 0, j = ans.size() - 1;i < j;i++,j--) {
            int temp = ans[i];
            ans[i] = ans[j];
            ans[j] = temp;
        }
        return ans;
    }
};