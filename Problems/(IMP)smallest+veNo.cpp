//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        /*
            0,-10,1,3,-20
            count = 1
            -20 -10 0 1 3
            
            arr[i] = 1 != arr[0] = 0
            1, -10, 0, 3, -20
            arr[3] = arr[arr[3] - 1]
            arr[3] = arr[2]
            0 -10 3 1 -20
            0
        */
        int ans;
        for(int i = 0; i < n; i++){
            if(arr[i] < 0){
                arr[i] = INT_MAX;
            }
        }
        for(int i = 0; i < n; i++){
            int val = abs(arr[i]);
            if(1 <= arr[i] && arr[i] <= n){
                if(arr[val - 1] > 0){
                    arr[val - 1] *= -1; 
                }else if(arr[val - 1] == INT_MAX){
                    arr[val - 1] = -1 * (n + 1);
                }
            }
        }
        for(int i = 1; i <= n; i++){
            if(arr[i - 1] >= 0){
                return i;
            }
        }
        return n + 1;
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
  //{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        for(int i = 0; i < n; i++){
            while(arr[i] > 0 && arr[i] <= n && arr[i] != arr[arr[i] - 1]){
                swap(arr[i], arr[arr[i] - 1]);
            }
        }    
        for(int i = 0; i < n; i++){
            if(arr[i] != i + 1){
                return i + 1;
            }
        }
        return n + 1;
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends
