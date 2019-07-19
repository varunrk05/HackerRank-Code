#include<bits/stdc++.h>
using namespace std;
void permuteStr(string str, string prefix) {
    if(str.length() == 0) {
        cout << prefix << " ";
    } else {
        for(int i = 0; i < str.length(); i++) {
            string rem = str.substr(0, i) + str.substr(i + 1);
            permuteStr(rem, prefix + str.at(i));
        }
    }
}

void permuteStr(string str) {
    permuteStr(str, "");
}

int main()
 {
	//code
	int t;
	string str;
	cin >> t;
	while(t--) {
	    cin >> str;
	    sort(str.begin(), str.end());
	    permuteStr(str);
	    cout << endl;
	}
	return 0;
}