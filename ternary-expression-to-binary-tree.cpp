
#include<bits/stdc++.h>
using namespace std;
struct Node{
	char data;
	Node *left,*right;
};
Node *newNode(char Data)
{
    Node *new_node = new Node;
    new_node->data = Data;
    new_node->left = new_node->right = NULL;
    return new_node;
}
void preorder(Node *root){
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
Node *convertExpression(string str,int i);
int main(){
	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		Node *root=convertExpression(str,0);
		preorder(root);
		cout<<endl;
	}
}
}
/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below
Node is as follows
struct Node{
	char data;
	Node *left,*right;
};
*/
Node* conExpUtil(string str, int& i, int n) {
    
    Node* root = newNode(str[i]);
    if(i == n - 1)
        return root;
    i++;
    if(str[i] == '?') {
        i++;
        root->left = conExpUtil(str, i, n);
        i++;
        root->right = conExpUtil(str, i, n);
    }
    return root;
}

Node *convertExpression(string str,int i)
{
    int n = str.length();
    return conExpUtil(str, i, n);
}