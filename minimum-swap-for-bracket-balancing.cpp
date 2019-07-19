#include<bits/stdc++.h>
using namespace std;

long swapBal(string s, int n) {
    vector<int> v;
    
    for(int i = 0; i < n; i++) {
        if(s[i] == '[')
            v.push_back(i);
    }
    
    int ind = 0,  c = 0; 
    long sum = 0;
    for(int i = 0; i < n; ++i) {
        if(s[i] == '['){
            ++c;
            ++ind;
        } else if(s[i] == ']'){
            --c;
        }
        
        if(c < 0) {
            sum += v[ind] - i;
            // cout << "sum update: " << sum << endl;
            swap(s[i], s[v[ind]]);
            ++ind;
            c = 1;
        }
    }
    
    return sum;
}

int main()
 {
	//code
	int t;
	cin >> t;
	while(t--) {
	    string s;
	    int n;
	    cin >> n;
	    cin >> s;
	    cout << swapBal(s, n) << endl;
	}
	return 0;
}