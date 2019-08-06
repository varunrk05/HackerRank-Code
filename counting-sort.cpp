{
// C Program for counting sort
#include <stdio.h>
#include <string.h>
#define RANGE 255
// The main function that sort the given string arr[] in
// alphabatical order
void countSort(char arr[]);
// Driver program to test above function
int main()
{
    long int t;
    scanf("%ld",&t);
    while(t--)
    {
        long int n;
        scanf("%ld",&n);
        char arr[n+1];
        scanf("%s",arr);
        countSort(arr);
        printf("%s", arr);
    }
    return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
// The main function that sort the given string arr[] in
// alphabatical order
#include <bits/stdc++.h>
using namespace std;
void countSort(char arr[])
{
// Your code goes here
    int count[256];
    // int n = strlen(arr);
    memset(count, 0, sizeof(count));
    
    for(int i = 0; arr[i]; i++)
        count[arr[i]] += 1;
        
    for(int i = 1; i < 256; i++)
        count[i] += count[i-1];
        
    int res[strlen(arr)];
    for(int i = 0; arr[i]; i++) {
        res[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
        
    for(int i = 0; arr[i]; i++)
        arr[i] = res[i];
}