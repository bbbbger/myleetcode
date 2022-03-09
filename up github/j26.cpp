#include<iostream>
using namespace std;
#include<queue>

  struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
  class Solution {
  public:
      bool isequal(TreeNode* t1, TreeNode* t2) {
          if (!t2)return true;
          //else if (t1 && !t2)return true;
          else if (t1 && t2) {
              if (t1->val == t2->val) {
                  return isequal(t1->left, t2->left) && isequal(t1->right, t2->right);
              }
          }
          return false;
      }
      bool isSubStructure(TreeNode* A, TreeNode* B) {
          if (!B || !A)return false;
          TreeNode* node1 = A;
          TreeNode* node2 = B;
          queue<TreeNode*> al;
          al.push(A);
          while (!al.empty()) {

              TreeNode* temp = al.front();
              if (isequal(temp, node2)) return true;
              else {
                  if (temp->left)al.push(temp->left);
                  if (temp->right)al.push(temp->right);
                  al.pop();
              }
          }
          return false;
      }
  };