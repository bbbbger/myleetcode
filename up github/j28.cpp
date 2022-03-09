#include<iostream>
using namespace std;
#include<vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    vector<TreeNode*> lrv;  //×óÖÐÓÒ
    vector<TreeNode*> rlv;  //ÓÒÖÐ×ó
    vector<int> innode1;
    vector<int> innode2;
    void lr(TreeNode* root) {
        if (!root) {
            //innode1.push_back(0);
            return;
        }
        lr(root->left);
        innode1.push_back(0);
        lrv.push_back(root);
        innode1.push_back(1);
        lr(root->right);
        innode1.push_back(0);
    }
    void rl(TreeNode* root) {
        if (!root) {
            //innode2.push_back(0);
            return;
        }
        rl(root->right);
        innode2.push_back(0);
        rlv.push_back(root);
        innode2.push_back(1);
        rl(root->left);
        innode2.push_back(0);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root)return true;
        lr(root);
        rl(root);
        int n = lrv.size();
        int n2 = innode1.size();
        for (int i = 0;i < n2;i++) {
            if (innode1[i] != innode2[i])return false;
        }
        for (int i = 0;i < n;i++) {
            if (lrv[i]->val != rlv[i]->val)return false;
        }
        return true;
    }
};