/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
#include <climits>
    bool check(Node* node, int min, int max) {
        if(node == nullptr) {
            return true;
        }
        
        if(node->data < min || node->data > max) {
            return false;
        }   
        
        return check(node->left, min, node->data-1) && check(node->right, node->data + 1, max);
    }

	bool checkBST(Node* root) {
        // if(root == nullptr) {
        //     return true;
        // } else if(root->left->data >= root->data || root->right->data <= root->data) {
        //     return false;
        // } else {
        //     checkBST(root->left);
        //     checkBST(root->right);
        //     return true;
        // }
        return check(root, INT_MIN, INT_MAX);
	}