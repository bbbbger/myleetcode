using namespace std;
#include<vector>
#include<queue>
#include<iostream>
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
  class Solution {
  public:
      vector<int> levelOrder(TreeNode* root) {
          vector<int>ans;
          if (!root)return ans;

          queue<TreeNode*> q;
          q.push(root);
          while (!q.empty()) {
              ans.push_back(q.front()->val);
              if (q.front()->left != nullptr)q.push(q.front()->left);
              if (q.front()->right != nullptr)q.push(q.front()->right);
              q.pop();
          }
          return ans;

      }
  };