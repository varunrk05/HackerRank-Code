#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void func(vector<int> ar1, vector<int> ar2, int n, int m) {
    vector<int> res;
    
    map<int, int> freq;
    
    for(int i = 0; i < n; i++) {
        freq[ar1[i]]++;
    }
    
    for(int i = 0; i < m; i++) {
        if(freq[ar2[i]] > 0) {
            while(freq[ar2[i]]--) {
                res.push_back(ar2[i]);
            }
            freq.erase(ar2[i]);
        }
    }
    
    int size = res.size();
    
    map<int, int> :: iterator it;
    for(it = freq.begin(); it != freq.end(); it++) {
        if(it->second > 0) {
            while(it->second--) {
                res.push_back(it->first);
            }
        }
    }
    sort(res.begin()+size, res.end());
    
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}

int main()
 {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int n, m;
	    cin >> n >> m;
	    vector<int> ar1, ar2;
	    int in;
	    for(int i = 0; i < n; i++) {
	        cin >> in;
	        ar1.push_back(in);
	    }
	    for(int i = 0; i < m; i++) {
	        cin >> in;
	        ar2.push_back(in);
	    }
	    func(ar1, ar2, n, m);
	}
	return 0;
}