// https://practice.geeksforgeeks.org/problems/queries-on-a-matrix0443/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    /*
        0 1 2 3 4
    0   2 2 2 0 -1
    1   0 0 0 0 0
    2   0 0 0 0 0
    3   0 0 0 -1 0
    4   0 0 0 0 -1
    */
    
  public:
  void solve(vector<vector<int>> &Queries, int q, vector<vector<int>> &ans){
      for(int i = 0; i < q; i++){
        int a = Queries[i][0];
        int b = Queries[i][1];
        int c = Queries[i][2];
        int d = Queries[i][3];
        for(int j = a; j <= c; j++){
             for(int k = b; k <= d; k++){
                 ans[j][k]++;
             }
        }
          
      }
      
  }
    vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries) {
        int q = Queries.size();
        vector<vector<int>> ans(n, vector<int>(n, 0));
        solve(Queries, q, ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, q;
        cin >> n >> q;
        vector<vector<int>> Queries;
        for (int i = 0; i < q; i++) {
            vector<int> cur(4);
            for (int j = 0; j < 4; j++) cin >> cur[j];
            Queries.push_back(cur);
        }
        Solution obj;
        vector<vector<int>> ans = obj.solveQueries(n, Queries);
        for (auto i : ans) {
            for (auto j : i) cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends
