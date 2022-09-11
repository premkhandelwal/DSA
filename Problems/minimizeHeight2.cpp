//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
// 2 6 3 4 7 2 10 3 2 1
/*
// 1 2 2 2 3 3 4 6  7 12
smallest = 3
largest = 9
minAbs = 6

minEle = 3
maxELe = 



*/
// 




// 6 7 7 7 8 8 9 11 12 7 

// 6 7 7 7 8 8 9 1 12 
class Solution {
    
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr, arr + n);
        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;
        int minAbs = arr[n -1] - arr[0];
        for(int i = 0; i < n -1; i++){
            int minEle = min(smallest, arr[i + 1] - k);
            int maxEle = max(largest, arr[i] + k);
            if(minEle < 0){
                continue;
            }
            minAbs = min(minAbs,abs(minEle - maxEle));
        }
        return minAbs;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
