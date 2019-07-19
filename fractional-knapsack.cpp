#include<bits/stdc++.h>
using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    double ra = (double)a.first / a.second;
    double rb = (double)b.first / b.second;
    return (ra > rb);
}

double fracKS(vector<pair<int, int>> v, int n, int w) {
    sort(v.begin(), v.end(), comp);
    
    int cw = 0;
    double cv = 0.0;
    
    for(int i = 0; i < n /*&& cw <= w*/; i++) {
        if(cw + v[i].second <= w) {
            cw += v[i].second;
            cv += v[i].first;
        } else {
            int rem = w - cw;
            cw += rem;
            cv += (v[i].first * ((double)rem / v[i].second));
            break;
        }
    }
    // cout << cw << endl;
    return cv;
}

int main()
 {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int n, w, iv, iw;
	    cin >> n >> w;
	    
	    vector<pair<int, int>> v;
	    for(int i = 0; i < n; i++) {
	        cin >> iv >> iw;
	        v.push_back(make_pair(iv, iw));
	    }
	    
	    cout << fixed << setprecision(2) << fracKS(v, n, w) << endl;
	}
	return 0;
}