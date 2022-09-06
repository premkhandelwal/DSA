//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
	   // 5 7 4 6
	   // 5 12 16 22
	   
	   //1 2 3 8
	   //1 3 6 14
        // Your code goes here
        int sumN = 0;
        int sumM = 0;
        for(int i = 0; i < n; i++){
            sumN += A[i];
        }
        for(int j = 0; j < m; j++){
            sumM += B[j];
        }
        int diff = (sumN - sumM)/2;
        if(diff == 0){
            return 1;
        }
        if((sumM+sumN)&1 != 0) return -1; 
        sort(A, A+n), sort(B, B+m);
        int i = 0, j = 0;
        while(i<n && j < m){
            if(A[i]-B[j] == diff){
                return 1;
            }
            else if(diff > A[i] - B[j]){
                i++;
            }else{
                j++;
            }
        }
        return -1;
	}
 

};
// 0001

//{ Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}






// } Driver Code Ends
