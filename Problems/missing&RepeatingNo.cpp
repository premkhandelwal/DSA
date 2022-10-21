//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int xor1 = arr[0];
        int x = 0;
        int y = 0;
        for(int i = 1; i < n; i++){
            xor1 = xor1 ^ arr[i];
        }
        for(int i = 1; i <= n; i++){
            xor1 = xor1 ^ i;
        }
        int set_bit_no = xor1 & ~(xor1 - 1);
        for(int i = 0; i < n; i++){
            if(arr[i] & set_bit_no){
                x = x ^ arr[i];
            }else{
                y = y ^ arr[i];
            }
        }
        for(int i = 1; i <= n; i++){
            if(i & set_bit_no){
                x = x ^ i;
            }else{
                y = y ^ i;
            }
        }
        int x_count = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == x){
                x_count++;
            }
        }
        int *ans = new int[2];
        if(x_count == 0){
            ans[0] = y;
            ans[1] = x;
            
        }else{
            ans[0] = x;
            ans[1] = y;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
