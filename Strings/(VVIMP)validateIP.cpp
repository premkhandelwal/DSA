//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            
            int n = s.length();
            int d = 0;
            if(s[0] == '.' || s[n-1] == '.'){
                return  0;
            }
            for(int i = 0; i < n - 1; i++){
                if(s[i] == '.' && s[i+1] == '.'){
                    return 0;
                }
                if(s[i] == '.'){
                    d++;
                }
            }
            if(d!=3){
                return 0;
            }
            string s1;
            for(int i = 0; i < n; i++){
                s1 = "";
                while(i < n && s[i] != '.'){
                    if(s[i] < '0' || s[i] > '9'){
                        return 0;
                    }
                    s1 += s[i];
                    i++;
                }
                int num = stoi(s1);
                if(num > 255){
                    return 0;
                }
                // Check for the case 0.0.0.0 or any single 1
                if(num == 0 && s1.length() == 1){
                    continue;  
                }
                // For trailing zeros. If leading zero, then not a vlid one
                int c = 0;
                while(num){
                    num/=10;
                    c++;
                }
                if(c != s1.length()){
                    return 0;
                }
                // This condition will fail for 0.0.0.0 if above 0 wala code is not written. 
                // c = 0 and s1 = '0' = 1, hence will return 0, but expected is 1
            }
            return 1;
        }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends
