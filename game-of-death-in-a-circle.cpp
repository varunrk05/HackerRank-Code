using namespace std;

int func(int n, int k) {
    if(n == 1)
        return 1;
    return (func(n - 1, k) + k - 1) % n + 1;
}

int main()
 {
	//code
	int t, n, k;
	cin >> t;
	while(t--) {
	    cin >> n >> k;
	    cout << func(n, k) << endl;
	}
	return 0;
}