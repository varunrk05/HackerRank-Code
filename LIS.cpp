//Longest Increasing Subsequence
#include<bits/stdc++.h>
using namespace std;

int func(vector<int> ar, int n) {
    int dp[n];
    // memset(dp, 1, sizeof(dp));
    dp[0] = 1;
    // dp[1] = 1;
    int max = 0;
    for(int i = 1; i < n; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(ar[j] < ar[i] && dp[i] < (dp[j] + 1))
                dp[i] = dp[j] + 1;
        }
        if(dp[i] > max)
            max = dp[i];
    }
    
    return max;
}

int main()
 {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int n, in;
	    cin >> n;
	    vector<int> ar;
	    for(int i = 0; i < n; i++) {
	        cin >> in;
	        ar.push_back(in);
	    }
	    cout << func(ar, n) << endl;
	}
	return 0;
}