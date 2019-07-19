#include<bits/stdc++.h>
using namespace std;

int func(int n) {
    int ar[n+1];
    ar[0] = 0;
    ar[1] = 1;
    
    for(int i = 2; i <= n; i++) {
        ar[i] = max(i, ar[i/2] + ar[i/3] + ar[i/4]);
    }
    
    return ar[n];
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