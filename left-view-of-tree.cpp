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
// A wrapper over leftViewUtil()
void leftView(Node *root)
{
   // Your code here
    queue<Node *> q;
   
    q.push(root);
    Node *tt = new Node(-1);
    Node *t;
    q.push(tt);
    int f = 1;
   
    while(!q.empty()) {
        t = q.front();
        q.pop();
        // cout << "1";
        // if(t == nullptr) {
        //     f = 1;
        //     q.push(nullptr);
        // } else {
        //     if(f == 1) {
        //         cout << t->data << " ";
        //         f = 0;
        //     } 
        // }
        
        if(t->data == -1) {
            f = 1;
            if(!q.empty()) {
                q.push(tt);
            }
        } else {
            
            if(f == 1) {
                cout << t->data << " ";
                f = 0;
            }
            
            if(t->left) {
                q.push(t->left);
            }
       
            if(t->right){
                q.push(t->right);
            }     
        }
       
    }
    
    return;
}
