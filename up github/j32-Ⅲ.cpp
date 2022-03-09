#include<iostream>
#include<vector>
using namespace std;
#include<deque>


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)return ans;
        deque<TreeNode*> dq;
        dq.push_back(root);
        int flag = 0;   //Å¼ÊýÕýÐò¡£ÆæÊýµ¹Ðò
        while (!dq.empty()) {
            vector<int> temp;
            
            for (int i = dq.size();i > 0;i--) {
                if (flag % 2 == 0) {
                    temp.push_back((*dq.begin())->val);
                    if (!(*dq.begin())->left)dq.push_back((*dq.begin())->left);
                    if (!(*dq.begin())->right)dq.push_back((*dq.begin())->right);
                    dq.pop_front();
                }
                else {
                    temp.push_back((*dq.rbegin())->val);
                    if (!(*dq.rbegin())->right)dq.push_front((*dq.rbegin())->right);
                    if (!(*dq.rbegin())->left)dq.push_front((*dq.rbegin())->left);
                    dq.pop_back();
                }
            }
            flag++;
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};