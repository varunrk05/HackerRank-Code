#include<bits/stdc++.h>
using namespace std;

int func(int n) {
    string s = to_string(n);
    int c = 0;
    sort(s.begin(), s.end());
    do {
        if(stoi(s) % 8 == 0)
            c += 1;
    } while(next_permutation(s.begin(), s.end()));
    
    return c;
}

int main()
 {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	   // cout << func(n) << endl;
	    if(func(n))
	        cout << "Yes\n";
	   else
	        cout << "No\n";
	}
	return 0;
}