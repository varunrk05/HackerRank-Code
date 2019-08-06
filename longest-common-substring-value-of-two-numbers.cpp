#include<bits/stdc++.h>
using namespace std;

// int func(long n, long m, int num, int i) {
//     if(n == 0 || m == 0)
//         return num;
//      else if(n == m)
//         return n;
//     else if(n % m == 0)    
//         return m;
//     else if(m % n == 0)
//         return n;
//     else if((n % 2) == (m % 2)) {
//         num += pow(2 ,i) * (n % 2);
//         return func(n/2, m/2, num, i * 10);
//     } else {
//         return max(func(n/2, m, num, i), func(n, m/2, num, i));
//     }
// }

long binToDec(string str) {
    // if(str == "")
    //     return 0;
    // long n = stoi(str);
    // cout << n << endl;
    int x = 0;
    int len = str.length();
    long res_num = 0;
    for(int i = len - 1; i >= 0; i--) {
        if(str[i] == '1')
            res_num += (long)pow(2, x);
        // n /= 10;
        x += 1;
        // cout << n << " " << i << " " << res_num << endl; 
    }
    
    return res_num;
}

string decToBin(long n) {
    string str;
    while(n > 0) {
        str.push_back(48 + n%2);
        n /= 2;
    }
    reverse(str.begin(), str.end());
    // cout << str << endl;
    return str;  
}

int func(unsigned long n, unsigned long m) {
    string sn = decToBin(n);
    string sm = decToBin(m);
    string res_str = "";
    int max_len = INT_MIN;
    int len = sn.length();
    int copy_len = len;
    
    while(len > 0) {
        
        int num_perm = copy_len - len + 1;    
        for(int i = 0; i < num_perm; i++) {
            
            string t = sn.substr(i, len);
            int substr_len = t.length();
            if(substr_len >= max_len && sm.find(t) != string::npos) {
                if(binToDec(t) > binToDec(res_str)) {
                    max_len = substr_len;
                    res_str = t;
                }
            }
        }
        len -= 1;
    }
    
    if(res_str == "")
        return -1;
        
    return binToDec(res_str);
    // return binToDec("1010");
}

int main()
 {
	//code
	int t;
	cin >> t;
	while(t--) {
	    unsigned long n, m;
	    cin >> n >> m;
	    int num = 0, i = 0;
	    cout << func(n, m) << endl;
	}
	return 0;
}