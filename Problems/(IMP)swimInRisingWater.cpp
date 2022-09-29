// https://leetcode.com/problems/swim-in-rising-water/

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // t, {r,c}
        int n = grid.size();
        pq.push({grid[0][0], {0,0}});
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<pair<int, int>> visited;
        visited.push_back({0,0});
        while(!pq.empty()){
            auto ele = pq.top();
            pq.pop();
            int t = ele.first;
            int r = ele.second.first;
            int c = ele.second.second;
            if(r == n -1 && c == n - 1){
                return t;
            }
            for(auto  dir : directions){
                int neighbourRow = dir.first + r;
                int neighbourCol = dir.second + c;
                if(neighbourRow < 0 || neighbourCol < 0 ||
                  neighbourRow == n || neighbourCol == n ||
                   find(visited.begin(), visited.end(), make_pair(neighbourRow, neighbourCol)) != visited.end()
                  ){
                    continue;
                }
                visited.push_back({neighbourRow, neighbourCol});
                pq.push({max(t, grid[neighbourRow][neighbourCol]), {neighbourRow, neighbourCol}});
            }
        }
        return 0;
    }
};
