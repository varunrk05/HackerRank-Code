#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j, int n) {
    return (i >= 0) && (i < n) && (j >= 0) && (j < n);
}

int func(vector<vector<int>> &ar, int n, bool vis[][20], int idx, int idy) {
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << ar[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    int x[4] = {-1, 0, 0, 1};
    int y[4] = {0, -1, 1, 0};
    
    queue<pair<int,int>> q;
    q.push(make_pair(idx, idy));
    pair<int,int> p;
    while(!q.empty()) {
        p = q.front();
        q.pop();
        vis[p.first][p.second] = true;
        
        // if(ar[p.first][p.second] == 2)
        //     return 1;
        // cout << "p: " << p.first << " " << p.second << " " << ar[p.first][p.second] << endl;
        for(int i = 0; i < 4; i++) {
            int nx = p.first + x[i];
            int ny = p.second + y[i];
            // cout << nx << " " << ny << " " << ar[nx][ny] << endl;
            if(isSafe(nx, ny, n)) {
                if(ar[nx][ny] == 3 && !vis[nx][ny]) {
                    q.push(make_pair(nx, ny));
                } else if(ar[nx][ny] == 2)
                    return 1;
            }
        }
    }
    
    return 0;
}

int main()
{
	//code
    int t;
    cin >> t;
    while(t--) {
        int n, in;
        cin >> n;
        vector<vector<int>> ar(n);
        
        bool vis[20][20];
        memset(vis, false, sizeof(vis));
        
        int idx, idy;
        for(int i = 0; i < n; i++) {
            ar[i] = vector<int>(n);
            for(int j = 0; j < n; j++) {
                cin >> in;
                // cout << in << " ";
                if(in == 1) idx = i, idy = j;
                ar[i][j] = in;
                // cout << ar[i][j] << " ";
            }
            // cout << endl;
        }
        // cout << endl;
        
        cout << func(ar, n, vis, idx, idy) << endl;
    }
    
	return 0;
}