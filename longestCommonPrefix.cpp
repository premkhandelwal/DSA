class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string first = strs.front();
        string last = strs.back();
        string commonPre = "";
        for(int i = 0; i<first.length(); i++){
            if(first[i] != last[i]){
                break;
            }else{
                commonPre += first[i];
            }
        }
        return commonPre;
    }
};
