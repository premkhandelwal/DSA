//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
// geeksforgeeks, geeks, geek, geezer
// geek geeks geeksforgeeks geezer 
// 
class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        sort(arr, arr + N);
        int len = min(arr[0].length(), arr[N-1].length());
        string ans = "";
        for(int i = 0; i < len; i++){
            if(arr[0][i] == arr[N-1][i]){
                ans += arr[0][i];
            }else{
                break;
            }
        }
        if(ans.size() == 0){
            return "-1";
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
