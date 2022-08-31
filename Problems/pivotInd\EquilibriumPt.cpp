//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

#include <vector>
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        if(n == 1){
            return 1;
        }
        vector<long long> pre(n, 0);
        pre[0] = a[0];
        for(int i = 1; i < n; i++){
            pre[i] = pre[i - 1] + a[i];
        }
        // 1, 3, 5, 2, 2
        // 1, 4, 9, 11, 13
        int l = 0, r = n - 1;
        for(int i = 0; i < n; i++){
            // cout << pre[l] << " " << pre[r] - pre[i] << endl;
            if(pre[l - 1] == pre[r] - pre[i]){
                
                return l + 1;
            }
            l++;
            // r--;
        }
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
