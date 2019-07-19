#include<bits/stdc++.h>
using namespace std;

int countPath(int m, int n) {
    if(m == 1 && n == 1) {
        return 1;
    }
    
    if(m == 1 && n != 1)
        return countPath(m , n - 1);
    if(m != 1 && n == 1)
        return countPath(m - 1, n);
    return countPath(m - 1, n) + countPath(m, n - 1);
}

int main()
 {
	//code
	int t, m, n;
	cin >> t;
	while(t--) {
	    cin >> m >> n;
	    int count = 0;
	    count = countPath(m, n);
	    cout << count << endl;
	}
	return 0;
}