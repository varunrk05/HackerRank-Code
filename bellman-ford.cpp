#include<bits/stdc++.h>
using namespace std;

int checkCycle(vector<int>edg[], int dis[], int v, int e) {
    for(int i = 1; i <= v-1; i++) {
        for(int j = 0; j < e; j++) {
            int s = edg[j][0];
            int d = edg[j][1];
            int w = edg[j][2];
            if(dis[s] != INT_MAX && dis[s] + w < dis[d]) 
                dis[d] = dis[s] + w;
        }
    }
    
	//Checks for negative weight cycle
    for(int i = 0; i < e; i++) {
        int s = edg[i][0];
        int d = edg[i][1];
        int w = edg[i][2];
        
        if(dis[s] + w < dis[d]) // If distance is smaller than the shortest distance found, then a negative weight cycle exists
            return 1;
    }
    
    return 0;
}

int main()
 {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int v, e;
	    cin >> v >> e;
	    vector<int> edg[50];
	    int x, y, z;
	    for(int i = 0; i < e; i++) {
	        cin >> x >> y >> z;
	        edg[i].push_back(x);
	        edg[i].push_back(y);
	        edg[i].push_back(z);
	    }
	    
	    int dis[100];
	    memset(dis, INT_MAX, sizeof(dis));
	    dis[0] = 0;
	    
	    cout << checkCycle(edg, dis, v, e) << endl;
	}
	return 0;
}