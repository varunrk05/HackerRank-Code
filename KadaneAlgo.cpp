#include<bits/stdc++.h>
using namespace std;

int maxSubsum(vector<int> v, int n) {
    int maxVal = INT_MIN, maxCal = 0;
    
    for(int i = 0; i < n; i++) {
        maxCal += v[i];
        if(maxVal < maxCal)
            maxVal = maxCal;
        if(maxCal < 0) 
            maxCal = 0;
    }
    
    return maxVal;
}

int main()
 {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int n, in;
	    cin >> n;
	    vector<int> v;
	    for(int i = 0; i < n; i++) {
	        cin >> in;
	        v.push_back(in);
	    }
	    cout << maxSubsum(v, n) << endl;
	}
	return 0;
}