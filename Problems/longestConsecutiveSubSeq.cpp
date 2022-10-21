//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    int findLongestConseqSubseq(int arr[], int N)
    {
        // [2, 6, 1
        set<int> hashSet(arr, arr + N);
        int longestSeq = 0;
        for(int i = 0; i < N; i++){
            if(hashSet.find(arr[i] - 1) == hashSet.end()){
                int currSeq = 0;
                while(hashSet.find(arr[i] + currSeq) != hashSet.end()){
                    currSeq++;
                }
                longestSeq = max(longestSeq, currSeq);
            }
        }
        return longestSeq;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends
