#include <bits/stdc++.h>
#include <stack>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {

  stack<char> st;
  int len = s.length();
  if (len % 2 != 0 || s.at(0) == '}' || s.at(0) == ']' || s.at(0) == ')') {
    return "NO";
  } else {
    // for(int i = 0; i < len/2; i++) {
    //     cout << c << " " << s.at(len - i - 1) << endl;
    //     if ((c == '{' && s.at(len - i - 1) == '}') || (c == '['
    //     && s.at(len - i - 1) == ']') || (c == '(' && s.at(len - i - 1)
    //     == ')')) {
    //         continue;
    //     } else {
    //         return "NO";
    //     }
    // }
    for(auto c:s) {
        if (c == '{' || c == '[' || c == '(') {
            st.push(c);
        } else if (c == '}') {
            if (st.empty() || st.top() != '{') {
                return "NO";
            }
            st.pop();
        } else if (c == ']') {
            if (st.empty() || st.top() != '[') {
                return "NO";
            }
            st.pop();
        } else if (c == ')') {
            if (st.empty() || st.top() != '(') {
                return "NO";
            }
            st.pop();
        }
    }
}

  return st.empty() ? "YES" : "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
