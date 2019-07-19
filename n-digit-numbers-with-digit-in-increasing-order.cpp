#include<bits/stdc++.h>
using namespace std;

void func(int num, int ind, int n) {
    if(n == 0) {
        cout << num << " ";
        // num /= 10;
        return;
    } 
    
    for(int i = ind + 1; i <= 9; i++) {
        // num = num * 10 + i;
        func(num * 10 + i, i, n-1);
        // num /= 10;
    }
}

int main()
 {
	//code
	int t, n;
	cin >> t;
	while(t--) {
	    cin >> n;
	    int num = 0;
	    func(num, 0, n);
	    cout << endl;
	}
	return 0;
}