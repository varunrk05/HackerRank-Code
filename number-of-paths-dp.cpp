#include<bits/stdc++.h>
using namespace std;

int func(int m, int n) {
    int path[m+1][n+1];
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == 1 && j == 1) 
                path[i][j] = 1;
            else if(i == 1 && j != 1)
                path[i][j] = path[i][j-1];
            else if(i != 1 && j == 1)
                path[i][j] = path[i-1][j];
            else
                path[i][j] = path[i-1][j] + path[i][j-1];
        }
    }
    
    return path[m][n];
}

int main()
 {
	//code
	int t, m, n;
	cin >> t;
	while(t--) {
	    cin >> m >> n;
	    cout << func(m, n) << endl;
	}
	return 0;
}