#include<bits/stdc++.h>
using namespace std;

int comp(int a, int b) {
    if(a == b)
        return 0;
    return (a > b) ? 1 : -1;
}

int main()
 {
	//code
	int n, t, in, m = -1;
	cin >> n;
	t = n;
	priority_queue<int> lpq;
	priority_queue<int, vector<int>, greater<int>> rpq;
	while(t--) {
	    cin >> in;
	    if(lpq.size() == 0 && rpq.size() == 0) {
	        lpq.push(in);
	        m = in;
	       // cout << "l\n";
	        cout << m << endl;
	    } else {
	       int c = comp(lpq.size(), rpq.size());
	       switch(c) {
	           case 1:  if(in < m) {
	                        rpq.push(lpq.top());
	                        lpq.pop();
	                        lpq.push(in);
	                       // cout << "l\n";
	                    } else {
	                        rpq.push(in);
	                       // cout << "r\n";
	                    }
	                    m = (lpq.top() + rpq.top()) / 2;
	                    break;
	                    
	           case 0:  if(in < m) {
	                        lpq.push(in);
	                       // cout << "l\n";
	                        m = lpq.top();
	                    } else {
	                        rpq.push(in);
	                       // cout << "r\n";
	                        m = rpq.top();
	                    }
	                    break;
	                    
	           case -1: if(in < m) {
	                        lpq.push(in);
	                       // cout << "l\n";
	                    } else {
	                        lpq.push(rpq.top());
	                        rpq.pop();
	                        rpq.push(in);
	                       // cout << "r\n";
	                    }
	                    m = (lpq.top() + rpq.top()) / 2;
	                    break;
	       }
	       // if(in > m) {
	       //     rpq.push(in);
	       //     cout << "Right\n";
	       // } else {
    	   //     lpq.push(in);
	       //     cout << "Left\n";
    	   // }
	       // int c = comp(lpq.size(), rpq.size());
	       // cout << c << endl;
	    
    	   // if(c == 0) {
	       //     m = (lpq.top() + rpq.top()) / 2;
	       // } else if(c == 1) {
	       //     m = lpq.top();
	       // } else {
	       //     m = rpq.top();
	       // }
	    
	        cout << m << endl;
	    }
	}
	return 0;
}