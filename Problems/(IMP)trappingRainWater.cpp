// https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1?page=1&status[]=unsolved&sortBy=submissions
// https://www.youtube.com/watch?v=m18Hntz4go8&t=321s
//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        int left = 0;
        int right = n  - 1;
        int lMax = arr[left];
        int rMax = arr[right];
        long long res = 0;
        while(left < right){
            if(lMax < rMax){
                left += 1;
                lMax = max(lMax, arr[left]);
                res += lMax - arr[left];
            }else{
                right -= 1;
                rMax = max(rMax, arr[right]);
                res += rMax - arr[right];
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends
