#include<bits/stdc++.h>
using namespace std;

int func(int n, int m, int ar[]) {
    int sc[n+1][m];
    
    int w, wo;
    
    for(int i = 0; i < m; i++) {
        sc[0][i] = 1; // To score 0 don't play a singe move
        sc[1][i] = sc[2][i] = 0; // You cant't score 1 or 2 points anyhow
    }
    
    for(int i = 3; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            w = (i - ar[j]) >= 0 ?  sc[i-ar[j]][j] : 0;
            wo = (j >= 1) ? sc[i][j-1] : 0;
            
            sc[i][j] = w + wo;
        }
    }
    
    return sc[n][m-1];
}

int main()
 {
	//code
	int t, n;
	int ar[] = {3, 5, 10};
	int m = sizeof(ar)/sizeof(ar[0]);
	cin >> t;
	while(t--) {
	    cin >> n;
	    cout << func(n, m, ar) << endl;
	}
	return 0;
}