#include <bits/stdc++.h>
using namespace std;
 
int subsequenceCount(string S, string T);
//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		cout<<subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
}
/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete this method*/
int subsequenceCount(string S, string T)
{
    //Your code here
    int m = T.length(), n = S.length();
    
    if(m > n)
        return 0;
    
    int occur[m+1][n+1];
    
    for(int i = 1; i <= m; i++) {
        occur[i][0] = 0;
    }
    
    for(int j = 0; j <= n; j++) {
        occur[0][j] = 1;
    }
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(T[i-1] != S[j-1])
                occur[i][j] = occur[i][j-1];
            else    
                occur[i][j] = occur[i][j-1] + occur[i-1][j-1];
        }
    }
    
    return occur[m][n];
}
 
