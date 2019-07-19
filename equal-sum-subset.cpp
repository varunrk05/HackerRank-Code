#include<bits/stdc++.h>
using namespace std;

bool subSumUtil(vector<int> v, int n, int s1, int s2, int stIdx) {
    if(s1 == s2) {
        return true;
    } 
    
    for(int i = stIdx; i < n; i++) {
        if(s2 + v[i] <= s1 - v[i]) {
            s2 += v[i];
            s1 -= v[i];
            
            if(subSumUtil(v, n, s1, s2, i + 1))
                return true;
                
            s2 -= v[i];
            s1 += v[i];
        }
    }
    
    return false;
}

void subSum(vector<int> v, int n, int s1, int s2) {
    // int f = 0;
    // subSumUtil(v, n, s1, s2);
    if(subSumUtil(v, n, s1, s2, 0)) {
        cout << "YES";
        return;
    }
    cout << "NO";
    return;
}

int main()
 {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int n, in, s1 = 0, s2 = 0;
	    cin >> n;
	    vector<int> v;
	    for(int i = 0; i < n; i++) {
	        cin >> in;
	        s1 += in;
	        v.push_back(in);
	    }
	    
	    if(s1 % 2 != 0) {
	        cout << "NO\n";
	        continue;
	    }
	    
	    subSum(v, n, s1, s2);
	    cout << endl;
	}
	return 0;
}