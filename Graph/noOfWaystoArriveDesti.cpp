//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
// 0 - 6
// 0 - 1
// 1 - 2
// 1 - 3
// 6 - 3
// 3 - 5
// 6 - 5
// 2 - 5
// 0 - 4
// 4 - 6
/*    
    
     
*/
#define mod (10^9 + 7)
class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto road : roads){
            int u = road[0];
            int v = road[1];
            int w = road[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //dist, node
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        pq.push({0,0});
        int ans = 0;
        while(!pq.empty()){
            long long d = pq.top().first;
            long long prev = pq.top().second;
            pq.pop();
            for(auto it: adj[prev]){
                int next = it.first;
                int nextdist = it.second;
                if(next == n -1){
                    if(dist[n-1] == d + nextdist){
                        ans = (ans + 1) % mod;
                    }
                    else if(dist[n-1] > d + nextdist){
                        ans = 1;
                        dist[n-1] = d + nextdist;
                    }
                }
                else if(d + nextdist <= dist[next]){
                    dist[next] = dist[prev] + nextdist;
                    pq.push({dist[next], next});
                }
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends
