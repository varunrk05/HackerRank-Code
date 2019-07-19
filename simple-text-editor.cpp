#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    cin >> t;
    int num, ch;
    stack<string> st;
    string s, og_s;
    // cout << t << endl;
    st.push(og_s);
    while(t > 0) {
        cin >> ch;
        // cout << ch << endl;
        switch(ch) {
            case 1: cin >> s;
                    og_s += s;
                    // cout << s << " " << og_s << endl;
                    st.push(og_s);
                    break;

            case 2: cin >> num;
                    og_s.erase(og_s.length() - num);
                    // cout << og_s << endl;
                    st.push(og_s);
                    break;

            case 3: cin >> num;
                    cout << og_s[num - 1] << endl;// << " " << og_s << endl;
                    break;

            case 4: st.pop();
                    og_s = st.top();
                    // cout << og_s << endl;
                    break;
        }
        t--;
    }

    return 0;
}
