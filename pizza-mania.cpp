#include<bits/stdc++.h>
using namespace std;

int func(int x, int s, int m, int l, int cs, int cm, int cl) {
    int cost[x+1];
    
    cost[0] = 0;
    
    for(int i = 1; i <= x; i++) {
        int sm = (i - s >= 0) ? cost[i - s] + cs : cs;
        int me = (i - m >= 0) ? cost[i - m] + cm : cm;
        int la = (i - l >= 0) ? cost[i - l] + cl : cl;
        
        cost[i] = min(sm, min(me, la));
    }
    
    // for(int i = 1; i <= x; i++) {
    //     cout << i << " " << cost[i] << "\n";
    // }
    
    return cost[x];
}

int main()
 {
	//code
	int t, x, s, m, l, cs, cm, cl;
	cin >> t;
	while(t--) {
	    cin >> x >> s >> m >> l >> cs >> cm >> cl;
	    cout << func(x, s, m, l, cs, cm, cl) << endl;
	}
	return 0;
}