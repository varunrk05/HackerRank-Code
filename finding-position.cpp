#include<bits/stdc++.h>
using namespace std;
int checkFac(int n) {
    while(n > 1) {
        if(n%2 != 0) {
            return 0;
        }
        n /= 2;
    }
    return 1;
}

int count(int n) {
    if(n == 1){
        return 1;
    }
    
    while(checkFac(n) == 0) {
        n--;
    }
    return n;
}

int main()
 {
	//code
	int t, n;
	cin >> t;
	while(t--) {
	    cin >> n;
	    int res = count(n);
	    cout << res << endl;
	}
	return 0;
}