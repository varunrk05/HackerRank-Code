#include <iostream>
#include <cstddef>

class Node {
    public: 
        int data;
        Node* left;
        Node* right;
        Node(int d) {
            data = d;
            left = nullptr;
            right = nullptr;
        }
};

class Solution {
    public:
        Node* insert(Node *root, int data) {
            if(root == nullptr) {
                return new Node(data);
            } else {
                Node *cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->left, data);
                    root->right = cur;
                }

                return root;
            }
        }
};

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    return 0;
}