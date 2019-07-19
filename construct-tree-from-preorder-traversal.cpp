{
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
struct Node* newNode (int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
void printInorder (struct Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder (node->right);
}
Node* constructTree(int n, int pre[], char preLN[]);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Node* root = NULL;
        int n;
        cin>>n;
        int pre[n];
        char preLN[n];
        for(int i=0; i<n; i++)cin>>pre[i];
        for(int i=0; i<n; i++)cin>>preLN[i];
        root = constructTree (n, pre, preLN);
        printInorder(root);
        cout<<endl;
    }
	return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/*Structure of the Node of the binary tree is as
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/
// function should return the root of the new binary tree formed
struct Node* construct(int n, int pre[], char preLN[], int& in) {
    if(in == n) {
        return nullptr;
    }
    
    Node* node = newNode(pre[in]);
    in++;
    
    if(preLN[in - 1] == 'N') {
        node->left = construct(n, pre, preLN, in);
        node->right = construct(n, pre, preLN, in);
    }
    
    return node;
}

struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
    int in = 0;
    return construct(n, pre, preLN, in);
}