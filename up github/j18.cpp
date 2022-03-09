#include<iostream>
using namespace std;

  struct ListNode {
    int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
  class Solution {
  public:
      ListNode* deleteNode(ListNode* head, int val) {
          if (head->val == val)return head->next;
          /*{
              ListNode* temp = head->next;
              delete head;
              head = NULL;
              return temp;
          }*/
          ListNode* node = head->next;
          ListNode* pre = head;
          while (node != nullptr) {
              if (node->val == val) {
                  pre->next = node->next;
                  /*delete node;
                  node = NULL;*/
                  return head;
              }
              pre = node;
              node = node->next;
          }
          return head;
      }
  };