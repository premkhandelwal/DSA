class Solution {
public:
    int f(int ind, vector<int>& dp){
        // if(ind == 0)
        if(ind == 0 || ind == 1){
            return 1;
        }
        if(dp[ind] != 0){
            return dp[ind];
        }
        int oneStep = f(ind - 1, dp);
        int twoStep = f(ind - 2, dp);
        return dp[ind] = oneStep + twoStep;
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1,0);
        return f(n, dp);
    }
};


-------------------------------------------------------------------------------------------------------------------------------
  
  class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1,-1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i<=n; i++){
            dp[i] = dp[i- 1] + dp[i - 2];
        }
        return dp[n];
    }
};
