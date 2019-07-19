#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the workbook function below.
int workbook(int n, int k, vector<int> arr) {
    // cout << "Start";
    vector<int> start;
    int s = 1;
    int curr_start;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            curr_start = 1;
        } else {
          curr_start = start.at(i - 2) + (arr.at(i - 2) / k) + ((arr.at(i - 2) % k) ? 1 : 0);
        }
        start.push_back(curr_start);
    }

    // for(int i = 0; i < n; i++) {
    //     cout << start.at(i) << " ";
    // }
    // cout << "starting page nos determined";

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (arr.at(i - 1) >= start.at(i - 1)) {
            int page_no = start.at(i - 1), page_count = 0;
            for (int j = 1; j <= arr.at(i - 1); j++) {
                page_count = (page_count + 1) % (k + 1);
                if (page_count == 0) {
                    page_no += 1;
                    page_count = 1;
                }
                if (j == page_no) {
                  count += 1;
                //   cout << i << " ";
                }   
            }
        }   
    }
    // cout << "\n";

    return count;
}

int main()
{
    int n, k;
    vector<int> arr;

    cin >> n >> k;
    int inp;
    for(int i = 1; i <= n; i++) {
        cin >> inp;
        arr.push_back(inp);
    }

    int res = workbook(n, k, arr);
    cout << res;
}
