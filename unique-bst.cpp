#include<bits/stdc++.h>
using namespace std;

// int countUniBST(int n, int i) {
    
// }

// int uniqueBST(int s, int e) {
    
//     if(s > e)
//         return 0;
//     int n = e - s + 1;
//     if(n == 1)
//         return 1;
//     if(n == 2)
//         return 2;
//     int l = 0, r = 0;
//     for(int i = s; i <= e; i++) {
//         l += uniqueBST(s, i-1);
//         r += uniqueBST(i+1, e);
//     }
    
//     if(l == 0)
//         return r;
//     else if(r == 0)
//         return l;
//     else return l * r;
// }

int binCoef(int n, int k) {
    
    if(k > n - k)
        k = n - k;
    
    int res = 1;
    for(int i = 0; i < k; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    
    return res;
}

int uniqueBST(int n) {
    
    int c = binCoef(2 * n, n);
    
    return c / (1 + n);
}

int main()
 {
	//code
	int t, n;
	cin >> t;
	while(t--) {
	    cin >> n;
	    cout << uniqueBST(n) << endl;
	}
	return 0;
}