//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++
class Solution
{
   public:
    string ReFormatString(string S, int k){
    	stack<char> stac;
    	int n = S.length();
    	int orgK = k;
    	for(int  i = n -1; i >= 0; i--){
    	    if(S[i] != '-'){
        	    if(k != 0){
        	        stac.push(toupper(S[i]));
        	        k--;
        	    }else{
        	        stac.push('-');
        	        k = orgK;
        	        i += 1;
        	    }
    	    }
    	    
    	}
    	string ans = "";
    	while(!stac.empty()){
    	    char ele = stac.top();
    	    stac.pop();
    	    ans.push_back(ele);
    	}
    	return ans;
    	
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string S;
	    cin>>S;
	    int K;
	    cin >> K;
	    Solution ob;  
	    string ans=ob.ReFormatString(S, K);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}

// } Driver Code Ends

---------------------------------------------------------------------------Eliminating extra space-------------------------------------------------------------
  
  //{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++
class Solution
{
   public:
    string ReFormatString(string S, int k){
    	string ans = "";
    	int n = S.length();
    	int cnt = 0;
    	for(int  i = n -1; i >= 0; i--){
    	    if(S[i] != '-'){
        	    if(cnt >= k){
        	       ans.push_back('-');
        	       cnt = 0;
        	    }
                ans.push_back(toupper(S[i])); 
                cnt++;
    	    }
    	    
    	}
    	reverse(ans.begin(), ans.end());
    	return ans;
    	
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string S;
	    cin>>S;
	    int K;
	    cin >> K;
	    Solution ob;  
	    string ans=ob.ReFormatString(S, K);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}

// } Driver Code Ends
