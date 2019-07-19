using namespace std;
#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>

vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {

    int n = scores.size();
    int m = alice.size();

    vector<int> rank, arank;
    cout << "Start";
    for (int i = 0; i < n; i++) {
        cout << "W 1";
        if(i == 0)      
            rank[i] = 1;
        else if(scores[i] == scores[i-1])
            rank[i] = rank[i-1];
        else {
            rank[i] = rank[i-1] + 1;
        }
        cout << "W 2";
    }
    int i = 0, j = n;
    cout << "W 3";
    for(; i < m; i++) {
      cout << "W 4";
      while (j >= 0 && alice[i] > scores[j])
        j--;

      if (j == -1)
        arank[i] = 1;
      else if (alice[i] == scores[j])
        arank[i] = rank[j];
      else if (alice[i] < scores[j])
        arank[i] = rank[j] + 1;
      cout << "W 5";
    }

    return arank;
}

int main() {
    int m, n;
    cin >> n;
    vector<int> scores, alice, result;

    for(int i = 0; i < n; i++)
        cin >> scores[i];
    cin >> m;
    for(int i = 0; i < n; i++)
        cin >> alice[i];

    result = climbingLeaderboard(scores, alice);

    for(int i = 0; i < n; i++) 
        cout << result[i] << "\n";
}
