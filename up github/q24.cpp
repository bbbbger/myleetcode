#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)return head;
        stack<ListNode*> L;
        ListNode* ans;
        while (head != NULL) {
            L.push(head);
            head = head->next;
        }
        ans=head = L.top();
        L.pop();
        while (!L.empty()) {
            ListNode* temp=L.top();
            L.pop();
            head->next = temp;
            head = temp;

        }
        head->next = NULL;
        return ans;
    }
};

//·¨¶þ
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)return head;
        else if (head->next == NULL)return head;
        ListNode* rear=head->next;
        head->next = NULL;
        
        while (rear != NULL) {
            ListNode* temp =rear->next;
            rear->next = head;
            head = rear;
            rear = temp;
        }
        return head;
      
    }
};