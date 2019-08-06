#include<bits/stdc++.h>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int longestSubStr(string str) {
    // int m = 0, c = 0;
    // int i = 0;
    // unordered_map<char, int> idx;
    // unordered_map<char, int> :: iterator it;
    // while(i < str.length()) {
    //     if(idx.find(str[i]) != idx.end()) {
    //         it = idx.find(str[i]); 
    //         if(i - c > it->second) {
    //             i++;
    //             c++;
    //         } else {
    //             m = max(m, c);
    //             c = i - it->second;
    //         }
    //     }
    //     idx.insert(make_pair(str[i], i));
    //     i++;
    //     c++;
    //     m = max(m, c);
    // }
    
    // return m;
    int vis[256];
    memset(vis, -1, sizeof(vis));
    
    int c = 1, m = 1;
    int x = 0;
    vis[str[0]] = 0;
    
    int n = str.length();
    for(int i = 1; i < n; i++) {
        x = vis[str[i]];
        if(x == -1 || i - c > x)
            c++;
        else {
            if(m < c)
                m = c;
                
            c = i - x;
        }
        vis[str[i]] = i;
    }
    if(c > m)
        m = c;
    
    return m;
}

int main()
 {
	//code
	int t;
	cin >> t;
	while(t--) {
	    string str;
	    cin >> str;
	    cout << longestSubStr(str) << endl;
	}
	return 0;
}