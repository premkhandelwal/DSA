//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
// L1 - prod1 - 6 prod2 - INT_MIN
	// Function to find maximum product subarray
// 	1 2 -3 4 -3
	long long maxProduct(vector<int> arr, int n) {
	    long long prod1 = 1;
	    long long prod2 = 1;
	    long long maxAns = INT_MIN;
	    for(long long a : arr){
	        long long temp = prod1 * a;
	        prod1 = max({a, prod1 * a, prod2 * a});
	        prod2 =  min({temp, prod2 * a,a });
	        maxAns = max(maxAns, prod1);
	    }
	    return maxAns;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
