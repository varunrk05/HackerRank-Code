#include<bits/stdc++.h>
using namespace std;

void printDis(int dis[][100], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dis[i][j] == 10000000)
                cout << "INF ";
            else 
                cout << dis[i][j] << " ";
        }
        cout << endl;
    }
}

void algo(int g[][100], int dis[100][100], int n) {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j  < n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    
    printDis(dis, n);
}

int main()
 {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int g[100][100], dis[100][100];
	    int n;
	    cin >> n;
	    
	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j < n; j++) {
	            cin >> g[i][j];
	            dis[i][j] = g[i][j];
	        }
	    }
	    algo(g, dis, n);
	}
	return 0;
}