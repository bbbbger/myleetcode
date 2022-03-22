#include<iostream>
using namespace std;
#include<vector>

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
#define pre left
#define next right
    vector<Node*> hel;
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr)return nullptr;
        midord(root);
        int n = hel.size();
        if (n == 1) {
            root->left = root;
            root->right = root;
            return root;
        }
        hel[0]->pre = hel[n - 1];
        hel[0]->next = hel[1];
        hel[n - 1]->next = hel[0];
        hel[n - 1]->pre = hel[n - 2];
        for (int i = 1; i < n - 1; i++) {
            hel[i]->pre = hel[i - 1];
            hel[i]->next = hel[i + 1];
        }
        return hel[0];
    }
    void midord(Node* node) {
        if (node == nullptr) {
            return;
        }
        midord(node->left);
        hel.push_back(node);
        midord(node->right);
    }
};

//中序遍历顺序就是有序的，只需要额外维护一个pre的node指针。
