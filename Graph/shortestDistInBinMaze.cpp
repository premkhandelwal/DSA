//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        if(source.first == destination.first && source.second == destination.second){
            return 0;
        }
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});
        vector<int> dr = {0, 0, 1, -1};
        vector<int> dc = {-1, 1, 0, 0};
        while(!q.empty()){
            auto ele = q.front();
            q.pop();
            int di = ele.first;
            int row = ele.second.first;
            int col = ele.second.second;
            for(int i = 0; i < 4; i++){
                int newRow = row + dr[i];
                int newCol = col + dc[i];
                if(newRow >= 0 && newCol >= 0 && newRow < n && newCol < m && grid[newRow][newCol] == 1 && di + 1 < dist[newRow][newCol]){
                    if(newRow == destination.first && newCol == destination.second){
                        return di + 1;
                    }
                    dist[newRow][newCol] = 1 + di;
                    q.push({di + 1, {newRow, newCol}});
                }
            }   
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends
