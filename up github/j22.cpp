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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        vector<ListNode*> vnode;
        while(head!=nullptr) {
            vnode.push_back(head);
            head = head->next;
        }
        
        return vnode[vnode.size() - k];
    }
};