
// -------------------------------------------------------------------------------Failing for I/P - -1, 1, -1, 1---------------------------------------------------------------------
// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/
//  -1 1 -1 1
//  -1 0 -1 0
class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        vector<int> prefSum(n, 0);
        prefSum[0] = arr[0];
        for(int i = 1; i < n; i++){
            prefSum[i] = prefSum[i - 1] + arr[i];
        }
        map<int, int> mMap ={};
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(mMap.find(prefSum[i]) == mMap.end()){
                mMap[prefSum[i]] = i;
            }
        }
        for(int i = 0; i < n; i++){
            if(mMap.find(prefSum[i]) != mMap.end()){
                ans = max(ans, i - mMap[prefSum[i]]);
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}

// } Driver Code Ends

-----------------------------------------------------------------------------------------------------------------------------------------------------
  
  //{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/
//  -1 1 -1 1
//  -1 0 -1 0
class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        int sum = 0;
        int ans = 0;
        map<int, int> mMap ={};
        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(sum == 0){
                ans = max(ans, i + 1);
            }
            if(mMap.find(sum) == mMap.end()){
                mMap[sum] = i;
            }else{
                ans = max(ans, i - mMap[sum]);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends
