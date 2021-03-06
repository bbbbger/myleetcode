#include<iostream>
using namespace std;

 struct ListNode {
    int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

 class Solution {
 public:
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         if (!l1)return l2;
         if (!l2)return l1;
         ListNode* head = NULL;
         if (l1->val <= l2->val) {
             head = l1;
             l1 = l1->next;
         }
         else {
             head = l2;
             l2 = l2->next;
         }
         ListNode* temp = head;
         while (l1 && l2) {

             if (l1->val <= l2->val) {
                 temp->next = l1;
                 l1 = l1->next;
                 temp = temp->next;
             }
             else {
                 temp->next = l2;
                 l2 = l2->next;
                 temp = temp->next;
             }
         }
         temp->next = l1 == NULL ? l2 : l1;
         return head;
     }
 };