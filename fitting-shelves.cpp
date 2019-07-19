#include <stdio.h>
#include <iostream>
// #include <bits/stdc++.h>

using namespace std;

void countWall(int w, int m, int n) {
    int cm = 0, cn = 0, minLen = w;
    int p = 0, q = 0, rem;
    
    while(w >= n) {
        p = w / m;
        rem =  w % m;
        
        if(rem <= minLen) {
            cm = p;
            cn = q;
            minLen = rem;
        }
        
        q += 1;
        w -= n;
    }
    
    cout << p << " " << q << " " << minLen;
    cout << endl;
    return;
}

int main() {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int w, m, n;
	    cin >> w >> m >> n;
	    countWall(w, m, n);
	}
	return 0;
}