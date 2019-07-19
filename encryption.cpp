#include <bits/stdc++.h>
#include <cmath>
#include <string>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {

    int n = s.length();
    int c = ceil(sqrt(n)), r = floor(sqrt(n));
    if(r * c < n)
        r += 1;
    string ret;
    int i = 0, k = 0;
    for(int j = 0; j < c; j++) {
        for(int i = j; i < n; i += c) {
            ret.append(s, i, 1);
            k++;
            cout << ret.at(k - 1);
        }
        ret.append(" ");
    }

    return ret;
}   

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
