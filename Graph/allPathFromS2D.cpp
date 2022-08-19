class Solution {
public:
    void dfsTraversal(vector<vector<int>>& graph, vector<vector<int>> &ans, vector<int> visited, int node, int target){
        visited.push_back(node);
        if(node == target){
            ans.push_back(visited);
        }
            for(auto i: graph[node]){
    if(find(visited.begin(), visited.end(), i) == visited.end()){
                    // visited.push_back(i);
                    dfsTraversal(graph, ans, visited, i, target);
                }
            }
         visited.pop_back();
        // visited.erase(remove(visited.begin(), visited.end()), node);
        // visited.erase(node);
        // remove(visited.begin(), visited.end(), node);
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size() - 1;
        int target = n;
        int source = 0;
        vector<vector<int>> ans;
        dfsTraversal(graph, ans, vector<int>(),source, target);
        return ans;
    }
};
