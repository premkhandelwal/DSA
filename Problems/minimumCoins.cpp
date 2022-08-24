class Solution {
public:
    int f(int ind, vector<int>& coins, int amountRem){
        if(ind == 0){
            if(amountRem % coins[0] == 0){
                return amountRem / coins[0];
            }
            return 1e9;
        }
        
        int pick = INT_MAX;
        if(coins[ind] <= amountRem){
            pick = 1+ f(ind, coins, amountRem - coins[ind]);
        }
        int notPick = f(ind - 1, coins, amountRem);
        // amountRem = 
        return min(pick, notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = f(n -1, coins, amount);
        if(ans == 1e9){
            return -1;
        }
        return ans;
    }
};

-------------------------------------------------------------------------------------------------------------------------------
  
  class Solution {
public:
    int f(int ind, vector<int>& coins, int amountRem, vector<vector<int>> dp){
        if(ind == 0){
            if(amountRem % coins[0] == 0){
                return amountRem / coins[0];
            }
            return 1e9;
        }
        if(dp[ind][amountRem] != -1){
            return dp[ind][amountRem];
        }
        int pick = INT_MAX;
        if(coins[ind] <= amountRem){
            pick = 1+ f(ind, coins, amountRem - coins[ind], dp);
        }
        int notPick = f(ind - 1, coins, amountRem, dp);
        // amountRem = 
        return dp[ind][amountRem] = min(pick, notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = f(n -1, coins, amount, dp);
        
        if(ans == 1e9){
            return -1;
        }
        return ans;
    }
};

-------------------------------------------------------------------------------------------------------------------------
  
  class Solution {
public
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        for(int i = 0; i<=amount; i++){
            if(i % coins[0] == 0){
                dp[0][i] = i / coins[0];
            }else{
                dp[0][i] = 1e9;
            }
             
        }
        for(int ind = 1; ind < n; ind++){
            for(int t = 0; t<=amount; t++){
                int pick = INT_MAX;
                if(coins[ind] <= t){
                    pick = 1+ dp[ind][t - coins[ind]];
                }
                int notPick = dp[ind - 1][t];
                dp[ind][t] = min(pick, notPick);
            }
            
        }
        int ans = dp[n -1][amount];
        if(ans >= 1e9){
            return -1;
        }
        return ans;
    }
};

-------------------------------------------------------------------------------------------------------------------------------
  
  class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
    vector<int> prev(amount + 1, 0), curr(amount + 1, 0);
    
        // vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        for(int i = 0; i<=amount; i++){
            if(i % coins[0] == 0){
                prev[i] = i / coins[0];
            }else{
                prev[i] = 1e9;
            }
             
        }
        for(int ind = 1; ind < n; ind++){
            for(int t = 0; t<=amount; t++){
                int pick = INT_MAX;
                if(coins[ind] <= t){
                    pick = 1+ curr[t - coins[ind]];
                }
                int notPick = prev[t];
                curr[t] = min(pick, notPick);
            }
            prev = curr;
            
        }
        int ans = prev[amount];
        if(ans >= 1e9){
            return -1;
        }
        return ans;
    }
};
