#include<iostream>
#include<unordered_map>
using namespace std;
// definition for a node.
class Node;
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)return nullptr;
        unordered_map<Node*, Node*> undmap;
        Node* node = head;
        while (node != nullptr) {
            Node* newnode = new Node(node->val);
            undmap[node] = newnode;
            node = node->next;
        }
        node = head;
        Node* ans = undmap[head];
        Node* temp = ans;
        while (node != nullptr) {
            ans->next = node->next != nullptr ? undmap[node->next] : nullptr;
            ans->random = node->random != nullptr ? undmap[node->random] : nullptr;
            node = node->next;
            ans = ans->next;
        }
        return temp;

    }
};