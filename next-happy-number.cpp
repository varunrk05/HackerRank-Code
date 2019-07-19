#include<bits/stdc++.h>
using namespace std;

bool check(int n, set<int>& s) {
    
    int sum = 0, dig;
    while(n > 0) {
        dig = n % 10;
        sum += dig * dig;
        n /= 10;
    }
    if(sum == 1){
        return true;
    }
    if(s.find(sum) != s.end()) {
        return false;
    }
    s.insert(sum);
    return check(sum, s);
}

int nextHappyNum(int n) {
    if(n == 0)
        return 1;
    n += 1;
    
    set<int> s;
    while(!check(n, s)){
        n++;
        s.clear();
    }
    
    return n;
}

int main()
 {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    int num = nextHappyNum(n);
	    cout << num << endl;
	}
	return 0;
}