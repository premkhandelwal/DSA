//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


//  0 0 0 1 1 1 1
// 

int transitionPoint(int arr[], int n) {
    int low = 0;
    int high = n - 1;
    if()
    while(low <= high){
        int mid = low + (high - low ) /2;
        if(arr[mid] == 1 && arr[low] == 0){
            return mid;
        }else if(arr[mid] == 0 && arr[high] == 1){
            return mid + 1;
        }else if(arr[mid] == 1){
            high = mid - 1; 
        }else if(arr[mid] == 0){
            low = mid + 1;
        }
        
    }
    return -1;
}


-----------------------------------------------------------------------------------------------------------------------------------
    
    //{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


//  0 0 0 1 1 1 1
// 

int transitionPoint(int arr[], int n) {
    int low = 0;
    int high = n - 1;
    int tp = -1;
    while(low <= high){
        int mid = low + (high - low ) /2;
        if(arr[mid] == 1){
            high = mid - 1;
            tp = mid;
        }else if(arr[mid] == 0){
            low = mid + 1;
        }
        
    }
    return tp;
}
