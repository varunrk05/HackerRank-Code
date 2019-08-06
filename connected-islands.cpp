{
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main() {
    
	int T;
	cin>>T;
	while(T--)
	{
		int N,M;
		cin>>N>>M;
		vector<int> A[N];
		for(int i=0;i<N;i++){
		    vector<int> temp(M);
		    A[i] = temp;
		    for(int j=0;j<M;j++){
		        cin>>A[i][j];
		    }
		}
		cout<<findIslands(A,N,M)<<endl;
	}
	return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/
/*you are required to complete this method*/
/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/

bool isSafe(int N, int M, int row, int col) {//, bool vis[][50]) {
    // if(row < 0 || row >= N || col < 0 || col >= M)
    //     return false;
    // return true;
    return (row >= 0) && (row < N) && (col >= 0) && (col < M);
}

int dfs(vector<int> A[], bool vis[][50], int N, int M, int i, int j) {
    
    static int xval[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int yval[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    vis[i][j] = true;
    
    for(int idx = 0; idx < 8; idx++) {
        if(isSafe(N, M, i + xval[idx], j + yval[idx])) {
            int new_i = i + xval[idx];
            int new_j = j + yval[idx];
            if(A[new_i][new_j] == 1 && !vis[new_i][new_j]) {
                dfs(A, vis, N, M, new_i, new_j);
            }
        }
    }
}

int findIslands(vector<int> A[], int N, int M)
{
// Your code here
    int c = 0;
    
    bool vis[50][50];
    memset(vis, false, sizeof(vis));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            // int idx = i * N + j;
            if(A[i][j] == 1 && !vis[i][j]) {
                dfs(A, vis, N, M, i, j);
                c += 1;
            }
        }
    }
    
    return c;
}
