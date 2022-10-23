//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    int steppingNumbers(int n, int m)
    {
        int ans = 0;
        queue<int> q;
        if(n == 0){
            ans++;
        }
        for(int i = 1; i <= 9; i++){
            q.push(i);    
        }   
        while(!q.empty()){
            int stepNum = q.front();
            q.pop();
            if(stepNum == 0 || stepNum > m){
                continue;
            }
            if(stepNum >= n && stepNum <= m){
                ans++;
            }
            int lastDigit = stepNum % 10;
            // 2 - 2*10 +  1
            // 23 - 23*10 + 1
            int stepNum1 = (stepNum * 10) + lastDigit + 1;
            int stepNum2 = (stepNum * 10) + lastDigit - 1;
            if(lastDigit == 9){
                q.push(stepNum2);
            }
            else if(lastDigit == 0){
                q.push(stepNum1);
            }
            else{
                q.push(stepNum1);
                q.push(stepNum2);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends
