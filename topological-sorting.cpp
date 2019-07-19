{
#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
/*  Function to check if elements returned by user 
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, int* res, vector<int> adj[]){
    bool flag =true;
    for(int i=0;i<V && flag;i++)
    {
        int n=adj[res[i]].size();
        for(auto j : adj[res[i]])
        {
            for(int k=i+1;k<V;k++)
            {
                if(res[k]==j )
                    n--;
            }
        }
        if(n!=0)
            flag =false;
    }
    if(flag==false)
        return 0;
    return 1;
}
// Driver Code
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,E;
        cin>>E>>N;
        int u,v;
        
        vector<int> adj[N];
        
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
        }
    
        int *res = topoSort(N, adj);
        
        cout<<check(N, res, adj)<<endl;
       
    }
}

}
/*This is a function problem.You only need to complete the function given below*/
// The Graph structure is as folows
/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*   NOTE: You must return dynamically allocated array 
*/
void topoSortUtil(int v, bool vis[], vector<int> adj[], stack<int>& res) {
    vis[v] = true;
    
    vector<int> :: iterator it;
    for(it = adj[v].begin(); it != adj[v].end(); it++) {
        if(!vis[*it]) 
            topoSortUtil(*it, vis, adj, res);
    }
    
    res.push(v);
}

int* topoSort(int V, vector<int> adj[])
{
    // Your code here
    bool vis[V];
    // cout << "1\n";
    memset(vis, false, sizeof(vis));
    // for(int i = 0; i < V; i++)
    //     vis[i] = false;
    stack<int> res;
    
    for(int v = 0; v < V; v++) {
        if(!vis[v])
            topoSortUtil(v, vis, adj, res);
    }
    
    int *r = new int[V];
    int i = 0;
    while(!res.empty()) {
        int x = res.top();
        res.pop();
        r[i++] = x;
    }
    
    return r;
}
