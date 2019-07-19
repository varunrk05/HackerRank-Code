{
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left,*right;
	Node(int d){
		data=d;
		left=right=NULL;
	}
};
int printCount(Node *root,int k);
void insert(Node *root,int a1,int a2,char lr){
	if(root==NULL)
		return;
	if(root->data==a1){
		switch(lr){
			case 'L':root->left=new Node(a2);
			break;
			case 'R':root->right=new Node(a2);
			break;
		}
	}
	else{
		insert(root->left,a1,a2,lr);
		insert(root->right,a1,a2,lr);
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
                cin>>n;
		Node *root=NULL;
		while(n--){
			int a1,a2;
			char lr;
			cin>>a1>>a2>>lr;
			if(root==NULL){
				root=new Node(a1);
				switch(lr){
					case 'L':root->left=new Node(a2);
					break;
					case 'R':root->right=new Node(a2);
					break;
				}
			}
			else{
				insert(root,a1,a2,lr);
			}
		}
		int k;
		cin>>k;
		cout<<printCount(root,k)<<endl;
	}
}
}
/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below
Node is as follows:
struct Node{
	int data;
	Node *left,*right;
	Node(int d){
		data=d;
		left=right=NULL;
	}
};*/

// void print(vector<int> ar, int i) {
//     for(int j = i; j < ar.size(); j++) {
//         cout << ar[j] << " ";
//     }
//     cout << endl;
// }

int printCountUtil(Node* root, int k, vector<int>& ar) {
    if(root == nullptr) {
        return 0;
    }
    int count = 0;
    ar.push_back(root->data);
    
    int lc = printCountUtil(root->left, k, ar);
    int rc = printCountUtil(root->right, k, ar);
    
    int s = 0;
    for(int i = ar.size() - 1; i >= 0; i--) {
        s += ar[i];
        
        if(s == k) {
            count++;
            //print(ar, j);
        }
    }
    ar.pop_back();
    
    return count + lc + rc;
}

int printCount(Node *root,int k)
{
//add code here.
    vector<int> ar;
    int count = 0;
    return printCountUtil(root, k, ar);
}{
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left,*right;
	Node(int d){
		data=d;
		left=right=NULL;
	}
};
int printCount(Node *root,int k);
void insert(Node *root,int a1,int a2,char lr){
	if(root==NULL)
		return;
	if(root->data==a1){
		switch(lr){
			case 'L':root->left=new Node(a2);
			break;
			case 'R':root->right=new Node(a2);
			break;
		}
	}
	else{
		insert(root->left,a1,a2,lr);
		insert(root->right,a1,a2,lr);
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
                cin>>n;
		Node *root=NULL;
		while(n--){
			int a1,a2;
			char lr;
			cin>>a1>>a2>>lr;
			if(root==NULL){
				root=new Node(a1);
				switch(lr){
					case 'L':root->left=new Node(a2);
					break;
					case 'R':root->right=new Node(a2);
					break;
				}
			}
			else{
				insert(root,a1,a2,lr);
			}
		}
		int k;
		cin>>k;
		cout<<printCount(root,k)<<endl;
	}
}
}
/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below
Node is as follows:
struct Node{
	int data;
	Node *left,*right;
	Node(int d){
		data=d;
		left=right=NULL;
	}
};*/

// void print(vector<int> ar, int i) {
//     for(int j = i; j < ar.size(); j++) {
//         cout << ar[j] << " ";
//     }
//     cout << endl;
// }

int printCountUtil(Node* root, int k, vector<int>& ar) {
    if(root == nullptr) {
        return 0;
    }
    int count = 0;
    ar.push_back(root->data);
    
    int lc = printCountUtil(root->left, k, ar);
    int rc = printCountUtil(root->right, k, ar);
    
    int s = 0;
    for(int i = ar.size() - 1; i >= 0; i--) {
        s += ar[i];
        
        if(s == k) {
            count++;
            //print(ar, j);
        }
    }
    ar.pop_back();
    
    return count + lc + rc;
}

int printCount(Node *root,int k)
{
//add code here.
    vector<int> ar;
    int count = 0;
    return printCountUtil(root, k, ar);
}