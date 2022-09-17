//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
//0 2 5 6 7    10
// speed = dist / time -> dist = speed * time

// 10 - 7 = 3  Expected
// 4 * 5 = 20 Actual

// 10 - 6 = 4 Expected
// 1 * 5 = 5 Good

// 10 - 3 = 7 Expected
// 1 * 5 = 5

class Solution {
public:
    int minimumSwaps(int c[],int v[],int n,int k,int b,int T)
    {
        int goodSheeps = 0;
        int badSheeps = 0;
        int swaps = 0;
        for(int i = n - 1; i >= 0; i--){
            int disRem = b - c[i];
            int actualDis = v[i] * T;
            if(disRem <= actualDis){
                goodSheeps += 1;
                swaps += badSheeps;
            }else{
                badSheeps += 1;
            }
            if(goodSheeps >= k){
                break;
            }    
        }
        if(goodSheeps >= k){
            return swaps;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main(){
    int t=1,testcases=1;
    cin>>t;
    while(t>=testcases)
    {
        int n,k,b,T;
        cin>>n>>k>>b>>T;
        int c[n];
        int v[n];
        for(auto &j:c)
            cin>>j;
        for(auto &j:v)
            cin>>j;
        Solution s;
        int ans=s.minimumSwaps(c,v,n,k,b,T);
        cout<<ans<<endl;
        testcases++;
    }
    // TIME;
    return 0;
}
// } Driver Code Ends
