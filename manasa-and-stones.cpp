#include <bits/stdc++.h>
#include <cmath>

using namespace std;

// Complete the stones function below.
vector<int> stones(int n, int a, int b) {

    vector<int> last;
    int dif = fabs(a - b);
    int min = (a <= b) ? a : b;
    int max = a + b - min;
    int num = min * (n - 1);
    last.push_back(num);
    if(a != b) {
        while(num != max * (n - 1)) {
            num += dif;
            last.push_back(num);
        }
    }

    return last;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int a;
        cin >> a;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int b;
        cin >> b;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // cout << "Test: " << T_itr << endl;
        vector<int> result = stones(n, a, b);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}
