class Solution {
public:
    string removeStars(string s) {
        int prev = -1;
        int curr = 0;
        string ans = "";
        for(int i = 0; i < s.length(); i++){
            if(s[curr] == '*'){
                ans.erase(ans.begin() + (prev));
                prev -= 1;
                curr++;
            }else{
                ans.push_back(s[curr]);
                // prev -= 2;
                curr++;
                prev++;
            }
            
            
        }
        return ans;
    }
};
