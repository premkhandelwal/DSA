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

---------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    int bfs(int m)
    {
        int ans = 1;
        queue<int> q;
        for(int i = 1; i <= 9; i++){
            q.push(i);    
        }  
        if (m < 0)
            return 0;
        if (m < 10)
            return m + 1;
        while(!q.empty()){
            int num = q.front();
            q.pop();
            ans++;
            int lastDigit = num % 10;
            // 2 - 2*10 +  1
            // 23 - 23*10 + 1
            int num1 = (num * 10) + lastDigit + 1;
            int num2 = (num * 10) + lastDigit - 1;
            if (num % 10 == 0)
            {
                if (num1 <= m)
                    q.push(num1);
            }
            // lastdigit is 9 then only one possible option that is append 8  that is  num2 here
            else if (num % 10 == 9)
            {
                if (num2 <= m)
                {
                    q.push(num2);
                }
            }
            // in all other case we will have 2 options append lastdigit+1 and lastDigit-1 at end of curr num
            else
            {
                if (num1 <= m)
                    q.push(num1);
                if (num2 <= m)
                    q.push(num2);
            }
        }
        return ans;
    }
    
    int steppingNumbers(int n, int m){
        return bfs(m) - bfs(n-1);
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
