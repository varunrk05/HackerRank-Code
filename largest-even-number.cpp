#include<bits/stdc++.h>
using namespace std;

void swap(char *x, char *y) {
    char t = *x;
    *x = *y;
    *y = t;
}

string bigEven(string s, int n) {
    sort(s.begin(), s.end(), greater<char>());
    if((s[n-1] - '0') % 2 == 0)
        return s;
    else {
        int idx = 0;
        for(idx = n - 1; idx >= 0; idx--) {
            if((s[idx] - '0') % 2 == 0)
                break;
        }
        if(idx >= 0) {
            for(int i = idx; i < n - 1; i++) {
                swap(&s[i], &s[i+1]);
            }
        }
        return s;
    }
}

int main()
 {
	//code
	int t;
	cin >> t;
	while(t--) {
	    string s;
	    cin >> s;
	    int n = s.length();
	    cout << bigEven(s, n) << endl;
	}
	return 0;
}