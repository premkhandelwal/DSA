class Solution {
public:
    void f(int count,vector<string> &arr, int n, int open, int closed, string currStr){
        // cout << "count " << count << " open " << open << " closed " << closed << " " << currStr <<endl;
        if(currStr.size() == n*2){
            arr.push_back(currStr);
            return;
        }
        if(open < n){
            // cout << "In Open " << count << endl;
            f(count + 1, arr, n, open + 1, closed, currStr + "(");
        }
        if(closed < open){
            // cout << "In Closed " << count << endl;
            f(count + 1, arr, n, open, closed + 1, currStr + ")");
        }
        // f(ind - 1, "()")
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans = {};
        f(0, ans, n, 0, 0, "");
        return ans;
    }
};
