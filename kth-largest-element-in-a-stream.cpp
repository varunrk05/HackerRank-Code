#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t, n, in, k;
	cin >> t;
	while(t--) {
	    cin >> k >> n;
	    priority_queue<int, vector<int>, greater<int>> pq;
	    for(int i = 0; i < n; i++) {
	        cin >> in;
	        if(pq.size() < k - 1) {
	            pq.push(in);
	            cout << "-1 ";
	        } else if(pq.size() == k - 1) {
	           // pq.pop();
	            pq.push(in);
	            cout << pq.top() << " ";
	        } else if(in >= pq.top()){
	            pq.pop();
	            pq.push(in);
	            cout << pq.top() << " ";
	        } else {
	            cout << pq.top() << " ";
	        }
	    }
	    cout << endl;
	}
	return 0;
}