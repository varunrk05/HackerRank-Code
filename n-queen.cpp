#include<bits/stdc++.h>
using namespace std;

void printQueens(int sol[][10], int n) {
    cout << "[";
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < n; i++){
            if(sol[i][j] == 1) { 
                cout << i + 1 << " "; 
                break; 
            }
        }
    }
    cout << "] ";
    
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << sol[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

bool isSafe(int sol[][10], int row, int col, int n) {
    int i, j;
    for(i = 0; i < col; i++)
        if(sol[row][i])
            return false;
            
    for(i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if(sol[i][j])
            return false;
            
    for(i = row, j = col; i < n && j >= 0; i++, j--)
        if(sol[i][j])
            return false;
          
    return true;
}

bool nQueensUtil(int sol[][10], int col, int n) {
    if(col == n) {
        printQueens(sol, n);
        return true;
    }
    
    bool res = false;
    for(int i = 0; i < n; i++) {
        if(isSafe(sol, i, col, n) == true) {
            sol[i][col] = 1;
            
            // if(nQueensUtil(sol, col+1, n))
            //     return true;
            res = nQueensUtil(sol, col+1, n) || res;
                
            sol[i][col] = 0;
        }
    }
    
    return res;
}

void nQueens(int sol[][10], int n) {
    // memset(sol, 0, sizeof(0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            sol[i][j] = 0;
    // printQueens(sol, n);
    // cout << endl;
    
    if(nQueensUtil(sol, 0, n) == false) {
        cout << "-1";
        return;
    }
    // free(sol);
    // delete sol;
    return;
}

int main()
 {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    int sol[10][10];
	   // memset(sol, 0, sizeof(sol));
	    
	    nQueens(sol, n);
	    cout << endl;
	}
	return 0;
}