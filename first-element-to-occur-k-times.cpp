#include<bits/stdc++.h>
using namespace std;

void func(vector<int> ar, int n, int k) {
    int found = -1;
    unordered_map<int, int> f;
    unordered_map<int, int> ind;
    
    for(int i = 0; i < n; i++) {
        f[ar[i]]++;
        if(ind.find(ar[i]) != ind.end()) {
            if(ind[ar[i]] > i) {
                ind[ar[i]] = i;
            }
        } else {
            ind[ar[i]] = i;
        }
    }
    int minm = INT_MAX;
    // cout << k << endl;
    for(auto it = f.begin(); it != f.end(); it++) {
        if(it->second == k) {
            found = 1;
            // cout << it->first << endl;
            minm = min(minm, ind[it->first]);
        }
    }
    
    if(found == 1) {
        cout << ar[minm] << endl;
        return;
    } else {
        cout << found << endl;
        return;
    }
}

int main()
 {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int n, k;
	    cin >> n >> k;
	    vector<int> ar;
	    int in;
	    for(int i = 0; i < n; i++) {
	        cin >> in;
	        ar.push_back(in);
	    }
	    func(ar, n, k);
	}
	return 0;
}