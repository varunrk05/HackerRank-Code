#include<bits/stdc++.h>
using namespace std;

int stairDP(int n) {
    // int dp[n+1];
    // memset(dp, 0, sizeof(dp));
    
    // dp[0] = dp[1] = 1;
    // for(int i = 2; i<= n; i++) {
    //     dp[i] = dp[i-2] + 1;
    //                |
    //              number of 2s
    // }
    
    // return dp[n];
    
    return n / 2 + 1;
}

int main()
 {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    cout << stairDP(n) << endl;
	}
	return 0;
}