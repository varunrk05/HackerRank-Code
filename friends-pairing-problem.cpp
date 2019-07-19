#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;

cpp_int func(int n) {
    cpp_int dp[n+1];
    
    for(int i = 0; i <= n; i++) {
        if(i <= 2)
            dp[i] = i;
        else {
            dp[i] = (dp[i-1] % 1000000007) + (((i-1) * dp[i-2]) % 1000000007);
        }
    }
    
    return (dp[n] % 1000000007);
}

int main()
 {
	//code
	int t, n;
	cin >> t;
	while(t--) {
	    cin >> n;
	    cout << func(n) << endl;
	}
	return 0;
}