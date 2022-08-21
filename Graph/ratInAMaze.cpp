// ----------------------------------------------------------------------------Failed Approach-----------------------------------------------------------------------------
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    int f( int n, int i, int j, vector<int>&TargetPos, int minSteps, vector<vector<int>>&visited, vector<vector<int>>&dp){
        if(i < 0 || j < 0 || i >= n || j>= n || visited[i][j] == 1){
            // cout << i << " ALl  " << j <<endl;
            return 99999999999999999999999;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(i == TargetPos[0] - 1 && j == TargetPos[1] -1){
            cout << i << " PALl  " << j <<endl;
            return minSteps;
        }
        visited[i][j] = 1;
        // cout << i << " MALl  " << j <<endl;
        int posA = f(n, i-2, j - 1, TargetPos, minSteps + 1, visited, dp) ;
        int posB = f(n, i+2, j - 1, TargetPos, minSteps + 1, visited, dp) ;
        int posC = f(n, i-2, j + 1, TargetPos, minSteps + 1, visited, dp) ;
        int posD = f(n, i+2, j + 1, TargetPos, minSteps + 1, visited, dp) ;
        int posE = f(n, i-1, j + 2, TargetPos, minSteps + 1, visited, dp) ;
        int posF = f(n, i+1, j + 2, TargetPos, minSteps + 1, visited, dp) ;
        int posG = f(n, i-1, j - 2, TargetPos, minSteps + 1, visited, dp) ;
        int posH = f(n, i+1, j - 2, TargetPos, minSteps + 1, visited, dp) ;
        visited[i][j] = 0;
        minSteps = min(minSteps+1,min(posA, min(posB, min(posC, min(posD, min(posE, min(posF, min(posG,posH))))))));
        return dp[i][j] = minSteps;
        // return 0;
    }
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    vector<vector<int>> visited(N, vector<int>(N,0));
        vector<vector<int>> dp(N +1, vector<int>(N,-1));
	    return f(N, KnightPos[0] -1 , KnightPos[1] -1, TargetPos, 0, visited, dp);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
