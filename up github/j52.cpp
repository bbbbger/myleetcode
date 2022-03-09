#include<iostream>
using namespace std;
#include<vector>


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB)return NULL;
        vector<ListNode*> vA;
        vector<ListNode*> vB;
        ListNode* temp = headA;
        while (temp) {
            vA.push_back(temp);
            temp = temp->next;
        }
        temp = headB;
        while (temp) {
            vB.push_back(temp);
            temp = temp->next;
        }
        temp = NULL;
        while (!vA.empty() && !vB.empty() && vA.back() == vB.back()) {
            temp = vA.back();
            vA.pop_back();
            vB.pop_back();
        }

        return temp;
    }
};