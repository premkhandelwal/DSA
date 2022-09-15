//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
// 20 12 18 4 - 54
// 8 5 4 3 2 1 - 23
// 
class Solution{
    public:
    static bool comp(int a, int b){
        return a > b;
    }
    int minSubset(vector<int> &Arr,int N){
        sort(Arr.begin(), Arr.end(), comp);
        int currCount = 0;
        long long sum = 0;
        long long leftSum = 0;
        for(int i = 0; i < N; i++){
            sum += Arr[i];
        }
        for(int i = 0; i < N; i++){
            if(leftSum <= sum - leftSum){
                leftSum += Arr[i];
                currCount += 1; 
            }else{
                break;
            }
        }
        return currCount;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        cout<<ob.minSubset(Arr,N)<<endl;
    }
    return 0;
}
// } Driver Code Ends
