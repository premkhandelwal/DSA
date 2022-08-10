class Solution {
public:
    vector<int> f(int n, vector<int> arr){
        if(n == 0){
            return {0};
        }
        arr = f(n - 1, arr);
        // int nVal = n;
        int count = 0;
        while(n){
            count += n & 1;
            n >>= 1;
        }
        arr.push_back(count);
        
        return arr;
    }
    // count = 0;
    vector<int> countBits(int n) {
        return f(n, {});
        
    }
};

-------------------------------------------------------------------------------------------------------------------------------
  
  class Solution {
public:
    vector<int> countBits(int n) {
        int offset = 1;
        vector<int> dp(n+1, 0);
        for(int i = 1; i < n + 1; i++){
            if(offset*2 == i){
                offset *= 2;
            }
            dp[i]=(dp[i - offset] + 1);
        }
        return dp;
    }
};
