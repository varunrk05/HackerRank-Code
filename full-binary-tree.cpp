{
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    struct Node *left, *right;
};
struct Node *newNode(char k)
{
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->key = k;
    node->right = node->left = NULL;
    return node;
}
void insert(Node *root,int a1,int a2,char lr){
	if(root==NULL)
		return;
	if(root->key==a1){
		switch(lr){
			case 'L':root->left=newNode(a2);
			break;
			case 'R':root->right=newNode(a2);
			break;
		}
	}
	else{
		insert(root->left,a1,a2,lr);
		insert(root->right,a1,a2,lr);
	}
}
bool isFullTree (struct Node* root);
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node* root = NULL;
		while(n-->0){
				int a1,a2;
				char lr;
				cin>>a1>>a2>>lr;
				if(root==NULL){
					root=newNode(a1);
					switch(lr){
						case 'L':root->left=newNode(a2);
						break;
						case 'R':root->right=newNode(a2);
						break;
					}
				}
				else{
					insert(root,a1,a2,lr);
				}
			}
		if (isFullTree(root))
			cout<<"1
";
		else
			cout<<"0
";
	}
    return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below
Node is as follows:
struct Node
{
    int key;
    struct Node *left, *right;
};
*/
bool isFullTree (struct Node* root)
{
//add code here.
    if(root == nullptr) {
        return true;
    }
    
    if((root->left && !root->right) || (!root->left && root->right)) {
        return false;
    }
    
    return isFullTree(root->left) && isFullTree(root->right);
}
