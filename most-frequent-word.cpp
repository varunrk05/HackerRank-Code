#include<bits/stdc++.h>
using namespace std;

string func(vector<string> v, int n) {
    unordered_map<string, pair<int, int>> m;//, id;
    int max_ind = INT_MIN, max_freq = INT_MIN;
    // string s = "";
    for(int i = 0; i < v.size(); i++) {
        m[v[i]].first++;
        m[v[i]].second = i;
        if(m[v[i]] >= max_freq && i > max_ind) {
            max_freq = m[v[i]];
            max_ind = i;
            // cout << v[max_ind] << " " << max_freq << endl;
        }
    }
    
    unordered_map :: iterator it;
    for(it = m.begin(); it != m.end(); it++) {
        cout << *it->first << " " << *it->second->frist << " " << *it->second->second << endl;
    }
    
    return v[max_ind];
}

int main()
 {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    vector<string> v;
	    string s;
	    for(int i = 0; i < n; i++)
	        cin >> s, v.push_back(s);
	        
	    cout << func(v, n) << endl;
	}
	return 0;
}