{
#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main()
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int a,b ;
   	    cin>>a>>b;
   	    int m,n;
   	    vector<int> adj[a+1];
        for(int i=0;i<b;i++){
            cin>>m>>n;
            adj[m].push_back(n);
        }
        // exit(0);
        cout<<kosaraju(a, adj)<<endl;
    }
    return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/
/*  Function to find the number of strongly connected components
*   using Kosaraju's algorithm
*   V: number of vertices
*   adj[]: array of vectors to represent graph
*/
void fillOrder(int v, bool vis[], stack<int>& s, vector<int> adj[]) {
    vis[v] = true;
    
    vector<int> :: iterator it;
    for(it = adj[v].begin(); it != adj[v].end(); it++) {
        if(!vis[*it]) {
            fillOrder(*it, vis, s, adj);
        }
    }
    
    s.push(v);
}

void getTranspose(vector<int> adj[], int V, vector<int> aT[]) {
    // vector<int> aT[V+1];
    
    for(int v = 0; v < V; v++) {
        vector<int> :: iterator it;
        for(it = adj[v].begin(); it != adj[v].end(); it++) {
            aT[*it].push_back(v);
        }
    }
}

void DFS(vector<int> aT[], bool vis[], int v) {
    vis[v] = true;
    // cout << v << " "; -> comment out while printing the scc
    vector<int> :: iterator it;
    for(it = aT[v].begin(); it != aT[v].end(); it++) {
        if(!vis[*it])
            DFS(aT, vis, *it);
    }
}

int kosaraju(int V, vector<int> adj[])
{
    // Your code here
    bool vis[V];
    memset(vis, false, sizeof(vis));
    
    stack<int> s;
    
    for(int v = 0; v < V; v++) {
        if(!vis[v]) {
            fillOrder(v, vis, s, adj);
        }
    }
    
    vector<int> aT[V+1];
    getTranspose(adj, V, aT);
    
    memset(vis, false, sizeof(vis));
    int count = 0;
    
    while(!s.empty()) {
        int v = s.top();
        s.pop();
        
        if(!vis[v]) {
            DFS(aT, vis, v);
            // cout << endl; -> Comment out while printing
            count += 1;
        }
    }
    
    return count;
}