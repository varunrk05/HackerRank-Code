#include<bits/stdc++.h>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int minNum(int ar[][10], int r, int c) {
    int dp[r][c];
    // int sum[r][c];
    
    // sum[0][0] = ar[0][0];
    // dp[0][0] = (sum[0][0] > 0) ? 1 : abs(sum[0][0]) - 1;
    
    // for(int i = 1; i < c; i++) {
    //     sum[0][i] = sum[0][i-1] + ar[0][i];
    //     dp[0][i] = (sum[0][i] > 0) ? 1 : abs(sum[0][i]) - 1;
    // }
    
    // for(int i = 1; i < r; i++) {
    //     sum[i][0] = sum[i-1][0] + ar[i][0];
    //     dp[i][0] = (sum[i][0] > 0) ? 1 : abs(sum[i][0]) - 1;
    // }
    
    // for(int i = 1; i < r; i++)
    //     for(int j = 1; j < c; j++) {
    //         sum[i][j] = min(sum[i-1][j], sum[i][j-1]) + ar[i][j];
    //         dp[i][j] = (sum[i][j] > 0) ? 1 : abs(sum[i][j]) + 1;
    //     }
        
    // return dp[r-1][c-1];
    
    dp[r-1][c-1] = (ar[r-1][c-1] > 0 ? 1 : abs(ar[r-1][c-1]) + 1);
    
    for(int i = c - 2; i >= 0; i--) {
        dp[r-1][i] = max(dp[r-1][i+1] - ar[r-1][i], 1);
    }
    
    for(int i = r-2; i >= 0; i--) {
        dp[i][c-1] = max(dp[i+1][c-1] - ar[i][c-1], 1);
    }
    
    for(int i = r - 2; i >= 0; i--) {
        for(int j = c - 2; j >= 0; j--) {
            int points = min(dp[i+1][j], dp[i][j+1]);
            dp[i][j] = max(points - ar[i][j], 1);
        }
    }
    
    return dp[0][0];
}

int main()
 {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int r, c;
	    cin >> r >> c;
	    int ar[10][10];
	    for(int i = 0; i < r; i++) 
	        for(int j = 0; j < c; j++)
	            cin >> ar[i][j];
	            
	    cout << minNum(ar, r, c) << endl;
	}
	return 0;
}