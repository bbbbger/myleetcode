using namespace std;
#include<iostream>


 struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {

public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root)return nullptr;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};