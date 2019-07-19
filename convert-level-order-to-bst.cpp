//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
void preorderTraversal(Node* root)
{
	if (!root)return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right); 
}
Node* constructBst(int arr[], int n);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        Node *root = constructBst(arr, n);
        preorderTraversal(root);
        cout<<endl;
    }
	return 0; 
}
}
/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/*
Structure of the Node of the node of the bst 
should be as
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/
// You are required to complete this function
Node* insert(Node* root, int x) {
    
    if(root == nullptr) {
        root = new Node(x);
        return root;
    }
    
    if(x < root->data) {
        root->left = insert(root->left, x);
    } else {
        root->right = insert(root->right, x);
    }
    return root;
}

Node* constructBst(int arr[], int n)
{
    // Code here
    if(n == 0) {
        return nullptr;
    }
    
    Node *root = new Node(arr[0]);
    for(int i = 1; i < n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}
