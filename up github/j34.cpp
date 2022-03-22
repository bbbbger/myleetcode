#include<vector>
using namespace std;



struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        this->tar = target;
        
        bintrace(root, 0);
        return ans;
    }
private:
    int tar;
    void bintrace(TreeNode* node,int count) {
        if (!node) {
            return;
        }
        v.push_back(node->val);
        if (!node->left&&!node->right&&count + node->val == tar) {          
            ans.push_back(v);
        }
        else {
            
            bintrace(node->left, count + node->val);
            bintrace(node->right, count + node->val);           
        }
        v.pop_back();
    }
};