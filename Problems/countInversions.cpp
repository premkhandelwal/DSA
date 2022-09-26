//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
   long long m(long long arr[], long long l, long long m, long long r)
    {
        long long temp[r-l+1];
        long long i,j,k;
        i = l;
        j = m+1;
        k=0;
        long long ci=0;
        
        while(i<=m && j<=r)
        {
            if(arr[i]<=arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
                ci+=(m-i+1);
            }
        }
        
        while(i<=m){
            temp[k++] = arr[i++];
        }
        
        
        while(j<=r){
            temp[k++] = arr[j++];   
        }
        
        for(long long i=l;i<=r;i++)
        {
            arr[i] = temp[i-l];
        }
        return ci;
    }
    
    long long  ms(long long arr[], long long low, long long high)
    {
        long long ci=0;
        if(low<high)
        {
            long long mid = (low+high)/2;
            ci += ms(arr, low, mid);
            ci += ms(arr, mid+1, high);
            ci += m(arr, low, mid, high);
        }
        return ci;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return ms(arr, 0, N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends
