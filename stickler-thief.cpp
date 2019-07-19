#include<bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int func(int n, vector<int> h) {
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    
    for(int i = 1; i <= n; i++) {
        if(i == 1)
            dp[i] = h[i-1];
        else {
            dp[i] = max(dp[i-2] + h[i-1], dp[i-1]);
        }
    }
    
    // for(int i = 1; i <= n; i++)
    //     cout << i << " " << dp[i] << endl;
    // cout << endl;
    
    return dp[n];
}

int main()
 {
	//code
	int t, n, in;
	cin >> t;
	while(t--) {
	    cin >> n;
	    vector<int> h;
	    for(int i = 0; i < n; i++){
	        cin >> in;
	        h.push_back(in);
	    }
	    
	    cout << func(n, h) << endl;
	}
	return 0;
}