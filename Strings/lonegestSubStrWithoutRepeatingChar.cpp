class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        map<char, int> charMap = {};
        int left = 0;
        int right = 0;
        int len = 0;
        while(right < n){
            if(charMap[s[right]] != NULL){
                left = max(left, charMap[s[right]]);
            }
            charMap[s[right]] = right + 1; 
            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};
