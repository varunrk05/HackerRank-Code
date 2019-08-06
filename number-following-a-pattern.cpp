#include<bits/stdc++.h>
using namespace std;

void func(string st) {
    // int n = s.length();
    int x = 1;
    
    stack<int> s;
    s.push(x);
    x += 1;
    vector<int> v;
    int t;
    for(int i = 0; st[i]; i++) {
        t = s.top();
        if(st[i] == 'D') {
            if(x < t) {
                while(!s.empty()) {
                    v.push_back(s.top());
                    s.pop();
                }
            }
        } else if(st[i] == 'I') {
            if(x > t) {
                while(!s.empty()) {
                    v.push_back(s.top());
                    s.pop();
                }
            }
        }
        s.push(x);
        x += 1;
    }
    while(!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
    
    for(int i = 0; i < v.size(); i++)
        cout << v[i];
    cout << endl;
}

int main()
 {
	//code
	int t;
	cin >> t;
	while(t--) {
	    string s;
	    cin >> s;
	    func(s);
	}
	return 0;
}