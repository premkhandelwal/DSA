//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    int count;
    void f(int ind, string target, int r, int c,vector<vector<char> > &mat, vector<vector<bool> > &visited){
        if(r < 0 or c < 0 or r >= mat.size() or c >= mat[0].size() or visited[r][c] == 1 or mat[r][c] != target[ind]){
            return;
        }
        if(ind == target.size() - 1){
            count++;
            return;
        }
        visited[r][c] = 1;
        f(ind + 1, target, r - 1, c, mat, visited);
        f(ind + 1, target, r, c+ 1, mat, visited);
        f(ind + 1, target, r, c - 1, mat, visited);
        f(ind + 1, target, r + 1, c, mat, visited);
        visited[r][c] = 0;
    }
    public:
    int findOccurrence(vector<vector<char> > &mat, string target){
        count = 0;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j]==target[0])
                {
                    vector<vector<bool>> visited(mat.size(), vector<bool>(mat[0].size(), false));
                    f(0, target, i, j, mat, visited);
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}

// } Driver Code Ends
