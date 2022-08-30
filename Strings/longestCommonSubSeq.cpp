https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_624879?leftPanelTab=1

int f(int ind1, int ind2, string s, string t){
    if(ind1 < 0 || ind2 < 0){
        return 0;
    }
    if(s[ind1] == t[ind2]){
        return 1 + f(ind1 - 1, ind2 - 1, s, t);    
    }
        return 0 + max(f(ind1, ind2 - 1, s, t), f(ind1 - 1, ind2,s,t));
    
}
int lcs(string s, string t)
{
//     vector<int>
    return f(s.length() - 1, t.length() - 1, s, t);
}

-------------------------------------------------------------------------------------------------------------------------------------------------------
  
  #include <vector>
int f(int ind1, int ind2, string s, string t,vector<vector<int>>&dp){
    if(ind1 < 0 || ind2 < 0){
        return 0;
    }
    if(dp[ind1][ind2] != -1){
        return dp[ind1][ind2];
    }
    if(s[ind1] == t[ind2]){
        return dp[ind1][ind2] =  1 + f(ind1 - 1, ind2 - 1, s, t, dp);    
    }
        return dp[ind1][ind2] = 0 + max(f(ind1, ind2 - 1, s, t, dp), f(ind1 - 1, ind2,s,t, dp));
    
}
int lcs(string s, string t)
{
    int n = s.length() - 1;
    int m = t.length() - 1;
    vector<vector<int>> dp(n + 1 ,vector<int>(m + 1, -1));
    return f(n,m, s, t, dp);
}
