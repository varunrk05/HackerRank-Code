#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    return (a.second.second < b.second.second);
}

void maxJobs(vector<pair<int, pair<int, int>>> v, int n) {
    sort(v.begin(), v.end(), comp);
    
    vector<int> res;
    int end = v[0].second.second;
    res.push_back(v[0].first + 1);
    for(int i = 1; i < n; i++) {
        if(v[i].second.first >= end) {
            end = v[i].second.second;
            res.push_back(v[i].first + 1);
        }
    }
    
    for(auto it = res.begin(); it != res.end(); it++){
        cout << *it << " ";
    }
    
    cout << endl;
    return;
}

int main()
 {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int n, in;
	    cin >> n;
	    vector<int> vs, vf, vi;
	    
	    for(int i = 0; i < n; i++){
	        cin >> in;
	        vs.push_back(in);
	       // vi.push_back(i);
	    }
	    
	    for(int i = 0; i < n; i++){
	        cin >> in;
	        vf.push_back(in);
	    }
	    
	    vector<pair<int, pair<int, int>>> v;
	    for(int i = 0; i < n; i++) {
	        v.push_back(make_pair(i, make_pair(vs[i], vf[i])));
	    }
	    
	    maxJobs(v, n);
	}
	return 0;
}