#include<bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int func(int n, vector<int> l) {
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            dp[i] = max(dp[i], dp[i - j - 1] + l[j]);
        }
    }
    // for(int i = 1; i <= n; i++)
    //     cout << i << " " << dp[i] << "\n";
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
	    vector<int> l;
	    for(int i = 0; i < n; i++) {
	        cin >> in;
	        l.push_back(in);
	       // cout << l[i] << " ";
	    }
	   // cout <<  endl;
	    cout << func(n, l) << endl;
	}
	return 0;
}