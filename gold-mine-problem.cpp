using namespace std;

int goldMine(int n, int m, int v[][20]) {
    int gold[m][n];//, ru = 0, r = 0, rd = 0;
    memset(gold, 0, sizeof(gold));
    
    for(int i =  n - 1; i >= 0; i--) {
        for(int j = 0; j < m; j++) {
            int r = (i == n - 1) ? 0 : gold[j][i+1];
            int ru = (j == 0 || i == n - 1) ? 0 : gold[j-1][i+1];
            int rd = (j == m - 1 || i == n - 1) ? 0 : gold[j+1][i+1];
            
            gold[j][i] = v[j][i] + max(r, max(ru, rd));
        }
    }
    
    int maxVal = gold[0][0];
    for(int i = 1; i < m; i++)
        maxVal = max(maxVal, gold[i][0]);
        
    return maxVal;
}

int main()
 {
	//code
	int t, n, m, in;
	cin >> t;
	int v[20][20];
	while(t--) {
	    cin >> m >> n;
	    for(int i = 0; i < m; i++){
	        for(int j = 0; j < n; j++) {
	            cin >> v[i][j];       
	        }
	   }     
	   cout << goldMine(n, m, v) << endl;
	}
	return 0;
}