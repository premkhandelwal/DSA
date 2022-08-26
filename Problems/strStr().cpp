class Solution {
public:
    int strStr(string haystack, string needle) {
        int ind;
        int j;
        for(int i = 0; i<haystack.length(); i++){
            for(j = 0; j<needle.length(); j++){
                if(needle[j] != haystack[i + j]){
                    break;
                }
            }
            if(j == needle.length()){
                return i;
            }
        }
        return -1;
    }
};
