{
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
#define MAX 100
// Structure of a tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
bool isSubtree(Node *T, Node *S);
void storeInorder(Node *, char[], int &);
void storePreOrder(Node *, char[], int &);
// Driver program to test above function
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        struct Node *child = NULL;
        map<int, Node *> m;
        int n;
        scanf(" %d
", &n);
        struct Node *t2 = NULL;
        while (n--) {
            Node *parent;
            char lr;
            int n1, n2;
            scanf("%d %d %c", &n1, &n2, &lr);
            if (m.find(n1) == m.end()) {
                parent = new Node(n1);
                m[n1] = parent;
                if (t2 == NULL) t2 = parent;
            } else
                parent = m[n1];
            child = new Node(n2);
            if (lr == 'L')
                parent->left = child;
            else
                parent->right = child;
            m[n2] = child;
        }
        struct Node *child1;
        map<int, Node *> m1;
        int nodes;
        scanf("%d
", &nodes);
        struct Node *t1 = NULL;
        while (nodes--) {
            Node *parent1;
            char lr1;
            int n3, n4;
            scanf("%d %d %c", &n3, &n4, &lr1);
            if (m1.find(n3) == m1.end()) {
                parent1 = new Node(n3);
                m1[n3] = parent1;
                if (t1 == NULL) t1 = parent1;
            } else
                parent1 = m1[n3];
            child = new Node(n4);
            if (lr1 == 'L')
                parent1->left = child;
            else
                parent1->right = child;
            m1[n4] = child;
        }
        cout << isSubtree(t1, t2);
        cout << "
";
    }
}
}
/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node
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
/*you are required to
complete this function */
#include <vector>
void inorder(Node* root, vector<int>& ar) {
    if(root == nullptr) {
        ar.push_back(-1);
        return;
    }
    
    inorder(root->left, ar);
    ar.push_back(root->data);
    inorder(root->right, ar);
}

void preorder(Node* root, vector<int>& ar) {
    if(root == nullptr) {
        ar.push_back(-1);
        return;
    }
    
    ar.push_back(root->data);
    preorder(root->left, ar);
    preorder(root->right, ar);
}

bool check(vector<int> ar1, vector<int> ar2) {
    int n = ar1.size();
    int m = ar2.size();
    
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(ar1[i] == ar2[j]) {
            i++;
            j++;
        } else {
            i++;
            j = 0;
        }
    }
    
    if(j == m) {
        return true;
    }
    return false;
}

bool isSubtree(Node* T1, Node* T2) {
    // Your code here
    // return 1 if T2 is subtree of T1 else 0
    
    vector<int> in1, in2, pre1, pre2;
    inorder(T1, in1);
    inorder(T2, in2);
    preorder(T1, pre1);
    preorder(T2, pre2);
    
    return check(in1, in2) && check(pre1, pre2);
}