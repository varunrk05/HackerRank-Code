#include<bits/stdc++.h>
using namespace std;
void sumSet(int n, vector<int> ar, multiset<int>& ms, int sum) {
    if(n == 0) {
        ms.insert(sum);
        return;
    }
    
    sumSet(n - 1, ar, ms, sum);
    sumSet(n - 1, ar, ms, sum + ar[n-1]);
}

int main()
 {
	//code
	int t, n, in;
	cin >> t;
	while(t--) {
	    cin >> n;
	    vector<int> ar;
	    for(int i = 0; i < n; i++) {
	        cin >> in;
	        ar.push_back(in);
	    }
	    int sum = 0;
	    multiset<int> ms;
	    sumSet(n, ar, ms, sum);
	    for(auto it = ms.begin(); it != ms.end(); it++) {
	        cout << *it << " ";
	    }
	    cout << endl;
	}
	return 0;
}