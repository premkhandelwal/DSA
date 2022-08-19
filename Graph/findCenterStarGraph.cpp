class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> countArr(n + 1, 0);
        for(auto t:edges){
            countArr[t[0]]++;
            countArr[t[1]]++;
        }
        for (int i = 1; i <= n; ++i) {
            if (countArr[i] == n - 1) return i;
        }
        return -1;
        
    }
};

------------------------------------------------------------------------------------
  
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        if(edges[0][0] == edges[1][0] || edges[0][1] == edges[1][0]){
            return edges[1][0];
        } 
        if(edges[0][0] == edges[1][1] || edges[0][1] == edges[1][1]){
            return edges[1][1];
        }
        return -1;
    }
};
