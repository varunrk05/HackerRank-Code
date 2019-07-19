#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int q, ch, x;
    cin >> q;
    stack<int> s1, s2;
    while(q > 0) {
        cin >> ch;
        if(ch == 1) {
            cin >> x;
            s1.push(x);
        } else {
            if(s2.empty()) {
                while(!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }

            if(ch == 2) {
                s2.pop();
            } else if(ch == 3) {
                cout << s2.top() << endl;
            }
        }
        q--;
    }

    return 0;
}
