{
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
// A simple recursive function to convert a given Binary tree to Doubly
// Linked List
// root --> Root of Binary Tree
// head --> Pointer to head node of created doubly linked list
void bToDLL(Node *root, Node **head_ref);
/* Function to print nodes in a given doubly linked list */
void printList(Node *node)
{
    Node *prev = NULL;
    while (node!=NULL)
    {
        cout << node->data << " ";
        prev = node;
        node = node->right;
    }
    cout << endl;
    while (prev!=NULL)
    {
        cout << prev->data << " ";
        prev = prev->left;
    }
    cout << endl;
}
void inorder(Node *root)
{
   if (root != NULL)
   {
       inorder(root->left);
       cout << root->data;
       inorder(root->right);
   }
}
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        Node *child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     Node *head = NULL;
     bToDLL(root, &head);
     printList(head);
  }
  return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/* Structure for tree and linked list
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
// This function should convert a given Binary tree to Doubly
// Linked List
void inorder(Node* root, vector<int>& ar) {
    if(root == nullptr) {
        return;
    }
    
    inorder(root->left, ar);
    ar.push_back(root->data);
    inorder(root->right, ar);
}

Node *node = nullptr;
void bToDLL(Node *root, Node **head_ref)
{
    // your code here
    if(root == nullptr) {
        return;
    }
    // vector<int> ar;
    // inorder(root, ar);
    
    // (*head_ref) = new Node(ar[0]);
    // int n = ar.size();
    // Node* node = (*head_ref);
    // for(int i = 1; i < n; i++) {
    //     Node* new_node = new Node(ar[i]);
    //     node->right = new_node;
    //     new_node->left = node;
    //     node = new_node;
    // }
    // node->right = (*head_ref);
    // (*head_ref)->left = node;
    
    // node = (*head_ref);
    // for(int i = 0; i < n; i++) {
    //     cout << node->right << " ";
    // }
    // cout << endl;
    // node = (*head_ref)->left;
    // for(int i = 0; i < n; i++) {
    //     cout << node->left << " ";
    // }
    // return;
    bToDLL(root->left, head_ref);
    
    if(*head_ref == nullptr) {
        *head_ref = root;
    } else {
        node->right = root;
        root->left = node;
    }
    node = root;
    
    bToDLL(root->right, head_ref);
    // node->right = (*head_ref); //These steps are commented out because of the print function
    // (*head_ref)->left = node;
}
