{
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
void reverseWords(char*);
/* Driver function to test above functions */
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[10000];
        cin >> s;
        reverseWords(s);
        cout<<endl;
    }
}
}
/*This is a function problem.You only need to complete the function given below*/

/*Function to reverse words*/
void reverseWords(char *s) {
    
    // Your code here
    stack<char> st;
    char* res = new char[strlen(s) + 1];
    
    int k = 0;
    for(int i = strlen(s) - 1; i >= 0; i--) {
        if(s[i] == '.') {
            while(!st.empty()) {
                res[k++] = st.top();
                st.pop();
            }
            if(i != 0) 
                res[k++] = '.';
        }
        else 
            st.push(s[i]);
    }
    
    if(!st.empty()) {
        while(!st.empty()) {
            res[k++] = st.top();
            st.pop();
        }   
    }
    res[k] = '\0';
    
    cout << res;
}
