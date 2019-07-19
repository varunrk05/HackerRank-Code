#include<bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int func(int n, int w, vector<int> v, vector<int> wt) {
    int dp[w+1];
    memset(dp, 0, sizeof(dp));
    
    for(int i = 1; i <= w; i++) {
        for(int j = 0; j < n; j++) {
            if(wt[j] <= i)
                dp[i] = max(dp[i], dp[i - wt[j]] + v[j]);
        }
    }
    
    return dp[w];
}

int main()
 {
	//code
	int t, n, w, in;
	cin >> t;
	while(t--) {
	    cin >> n >> w;
	    vector<int> v, wt;
	    for(int i = 0; i < n; i++) {
	        cin >> in;
	        v.push_back(in);
	    }
	    
	    for(int i = 0; i < n; i++) {
	        cin >> in;
	        wt.push_back(in);
	    }
	    
	    cout << func(n, w, v, wt) << endl;
	}
	return 0;
}