
#include<vector>
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
      vector<vector<int>> levelOrder(TreeNode* root) {
          vector<vector<int>>ans;
          if (!root)return ans;

          queue<TreeNode*> q;
          q.push(root);
          while (!q.empty()) {
              vector<int>temp;
              int n = q.size();
              for (int i = 0;i < n;i++) {

                  temp.push_back(q.front()->val);
                  if (q.front()->left != nullptr)q.push(q.front()->left);
                  if (q.front()->right != nullptr)q.push(q.front()->right);
                  q.pop();
              }
              ans.push_back(temp);
              temp.clear();
          }
          return ans;

      }
  };