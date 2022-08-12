class Solution {
public:
    int f(int n){
        if(n <= 0){
            return 0;
        }if(n == 1){
            return 1;
        }if(n == 2){
            return 1;
        }
        return f(n-1) + f(n-2) + f(n - 3);
    }
    int tribonacci(int n) {
        return f(n);
    }
};

-----------------------------------------------------------------------------------------

class Solution {
public:
    int f(int n, vector<int> dp){
        if(n <= 0){
            return 0;
        }if(n == 1){
            return 1;
        }if(n == 2){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        return dp[n] = f(n-1, dp) + f(n-2, dp) + f(n - 3, dp);
    }
    int tribonacci(int n) {
        return f(n, vector<int>(n + 1, -1));
    }
};

--------------------------------------------------------------------------------------
  
class Solution {
public:
    int tribonacci(int n) {
        if(n == 0){
            return 0;
        }if(n == 1){
            return 1;
        }if(n == 2){
            return 1;
        }
        int prev3 = 0;
        int prev2 = 1;
        int prev = 1;
        for(int i = 3; i<=n; i++){
            int curr = prev3 + prev2 + prev;
            prev3 = prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;        
    }
};
