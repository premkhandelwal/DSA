------------------------------------------------------------------------Memoization using dp array---------------------------------------------------------------------
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    // weight is the weight of ith values
    // [1, 2, 3]
    // weight [4, 5, 1]
    
    int f(int ind,int currVal, int wt[], int val[], vector<vector<int>> dp){
        if(ind == 0){
            if(wt[0] <= currVal){
                return val[0];
            }
            return 0;
        }
        if(dp[ind][currVal] != -1){
            return dp[ind][currVal];
        }
        int pick = INT_MIN;
        if(wt[ind] <= currVal)  
            pick = f(ind - 1, currVal - wt[ind], wt, val, dp) + val[ind];
        int notPick = f(ind - 1, currVal, wt,val, dp);
        return dp[ind][currVal] = max(pick, notPick);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n , vector<int>(W+1,-1));
        return f(n -1, W, wt, val, dp);   
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
-----------------------------------------------------------------------------Tabulation using dp array---------------------------------------------------------------
  //{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    // weight is the weight of ith values
    // [1, 2, 3]
    // weight [4, 5, 1]

    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n , vector<int>(W+1,0));
        for(int mW = wt[0]; mW <= W; W++) dp[0][mW] = val[0];
        
        for(int ind = 1; ind < n; ind++){
            for(int wet = 0; wet <= W; wet++){
                int pick = INT_MIN;
                if(wt[ind] <= W)  
                    pick = dp[ind - 1][wet - wt[ind]] +  val[ind];
                int notPick = dp[ind - 1][wet];
                dp[ind][wet] = max(pick, notPick);
            }
        }
        
        return dp[n -1][W];   
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
--------------------------------------------------------------------------Prev and Curr Array--------------------------------------------------------------------------
  

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    // weight is the weight of ith values
    // [1, 2, 3]
    // weight [4, 5, 1]
    
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<int> prev(W + 1, 0);
        vector<int> curr(W +1,0);
        for(int mW = wt[0]; mW <= W; mW++) prev[mW] = val[0];
        
        for(int ind = 1; ind < n; ind++){
            for(int wet = 0; wet <= W; wet++){
                int pick = INT_MIN;
                if(wt[ind] <= wet)  
                    pick = prev[wet - wt[ind]] +  val[ind];
                int notPick = prev[wet];
                curr[wet] = max(pick, notPick);
            }
            prev = curr;
        }
        
        return prev[W];   
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}

----------------------------------------------------------------------------------Prev Array---------------------------------------------------------------------------
  
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    // weight is the weight of ith values
    // [1, 2, 3]
    // weight [4, 5, 1]

    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<int> prev(W + 1, 0);
        // vector<int> curr(W +1,0);
        for(int mW = wt[0]; mW <= W; mW++) prev[mW] = val[0];
        
        for(int ind = 1; ind < n; ind++){
            for(int wet = W; wet >= 0; wet--){//Changed this line
                int pick = INT_MIN;
                if(wt[ind] <= wet)  
                    pick = prev[wet - wt[ind]] +  val[ind];
                int notPick = prev[wet];
                prev[wet] = max(pick, notPick);
            }
            // prev = curr;
        }
        
        return prev[W];   
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
