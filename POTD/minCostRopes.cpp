//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    // 2 4 6 7 9
    
    // 4 3 2 6
    //  2 3 4 6
    // 2 + 3 = 5 
    // cA = [5, 9, 15]
    // 5 + 4= 9; 4 + 6 = 10
    
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        sort(arr, arr + n);
        if(n == 1){
            return arr[0];
        }
        vector<int> costArray;
        costArray.push_back(arr[0] + arr[1]);
        int i = 2;
        while(i < n){
            int q = costArray.size();
            if((i + 1 < n) && (arr[i] + arr[i + 1]) <= (arr[i] + costArray[q - 1])){
                int temp = costArray[q - 1];
                costArray.push_back(arr[i + 1] + arr[i]);
                costArray.push_back(arr[i + 1] + arr[i] + temp);
                i += 2;
            }else{
                costArray.push_back(arr[i] + costArray[q - 1]);
                i += 1;
            }
        }
        long long totalCost = 0;
        for(long long c : costArray){
            // cout << c << " ";
            totalCost += c; 
        }
        // cout << endl;
        return totalCost;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends

// ------------------------------------------------------------Using Priorty Queue----------------------------------------

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        long long ans = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(int i = 0; i < n; i++){
            pq.push(arr[i]);
        }
        while(pq.size() > 1){
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            long long sum = first + second;
            ans += sum;
            pq.push(sum);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
