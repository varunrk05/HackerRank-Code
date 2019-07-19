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
void verticalOrder(Node *root);
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d
",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     verticalOrder(root);
     cout << endl;
  }
  return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node has data, pointer to left child
   and a pointer to right child 
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
void getOrder(Node* root, map<int, vector<int>>& m, int hd) {
    if(root == nullptr) {
        return;
    }
    
    m[hd].push_back(root->data);
    
    getOrder(root->left, m, hd - 1);
    getOrder(root->right, m, hd + 1);
}
 
void verticalOrder(Node *root)
{
    //Your code here
    int hd = 0;
    map<int, vector<int>> m;
    getOrder(root, m, hd);
    
    for(auto i = m.begin(); i != m.end(); i++) {
        for(int it = 0; it < i->second.size(); it++) {
            cout << i->second[it] << " ";
        }
    }
}
