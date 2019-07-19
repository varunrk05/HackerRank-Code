{

#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<numTrees(n)<<"
";
    }
}	
}
/*This is a function problem.You only need to complete the function given below*/

// Functiuon to return number of trees
int numTrees(int n) {
    // Your code here
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    
    dp[0] = dp[1] = 1;
    
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i] += dp[j-1] * dp[i-j];
        }
    }
    
    return dp[n];
}