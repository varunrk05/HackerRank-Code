#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, ch, inp, max = 0;
    stack<int> s;

    cin >> n;
    while(n > 0) {
        cin >> ch;

        switch(ch){
            case 1: cin >> inp;
                    if(s.empty()) {
                        max = inp;
                        s.push(inp);
                    }
                    else{
                        if (inp > max) {
                            s.push(2 * inp - max);
                            max = inp;
                        } else {
                            s.push(inp);
                        }
                    } 
                    break;

            case 2: if(s.top() <= max) { 
                        s.pop();
                    } else if(s.top() > max) {
                        max = 2 * max - s.top();
                        s.pop();
                    }
                    break;

            case 3: cout << max << endl;
        }

        n -= 1;
    }

    return 0;
}
