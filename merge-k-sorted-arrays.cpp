{
#include<bits/stdc++.h>
#define N 100
using namespace std;
int *mergeKArrays(int arr[][N],int k);
void printArray(int arr[], int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}
int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    int arr[N][N];
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	int *output = mergeKArrays(arr, k);
	printArray(output, k*k);
	cout<<endl;
}
	return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/
// your task is tocomplete this function
// function should return an pointer to output array int*
// of size k*k
struct comp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return(a.first >= b.first);
    }
};

int *mergeKArrays(int arr[][N], int k)
{
//code here
    int *ar = new int[k*k];
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    int idx = 0;
    int cur_idx[k];
    memset(cur_idx, 0, sizeof(cur_idx));
    
    for(int i = 0; i < k; i++)
        pq.push(make_pair(arr[i][0], i));
        
    for(int i = 0; i < k*k; i++) {
        int min = pq.top().first;
        int ind = pq.top().second;
        pq.pop();
        ar[idx++] = min;
        
        int new_idx = cur_idx[ind] + 1;
        if(new_idx < k) {
            cur_idx[ind] = new_idx;
            pq.push(make_pair(arr[ind][cur_idx[ind]], ind));
        }
    }
    
    return ar;
}