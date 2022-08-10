class Solution {
public:
    int f(int ind, vector<int> a, vector<int> dp){
        if(ind == 0){
            return a[ind];
        }
        if(ind < 0){
            return 0;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        int pick = a[ind] + f(ind - 2, a, dp);
        int notPick = 0 + f(ind - 1, a, dp);
        return dp[ind] = max(pick, notPick);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        return f(n - 1, nums,vector<int>(n, -1));    
    }
};

---------------------------------------------------------------------------------------
  
  class Solution {
public:
   
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        for(int ind = 1; ind<n; ind++){
            int pick = nums[ind];
            if(ind - 2 >= 0){
                pick += dp[ind - 2];
            }
            int notPick = 0 + dp[ind - 1];
            dp[ind] = max(pick, notPick);
        }
        return dp[n-1];
    }
};

-----------------------------------------------------------------------------------------
  
  
  class Solution {
public: 
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n, -1);
        int prev = nums[0];
        int prev2 = 0;
        // dp[0] = nums[0];
        for(int ind = 1; ind<n; ind++){
            int pick = nums[ind];
            if(ind - 2 >= 0){
                pick += prev2;
            }
            int notPick = 0 + prev;
            int curr = max(pick, notPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
