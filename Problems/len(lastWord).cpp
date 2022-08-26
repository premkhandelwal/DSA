class Solution {
public:
    int lengthOfLastWord(string s) {
        int left = s.length(), right = s.length();
        bool wordStarted = false;
        for(int i = s.length() - 1; i>=0; i--){
            if(int(s[i]) != 32){
                wordStarted = true;
                left = left - 1;
            }else{
                cout << i << "  " << wordStarted << endl;
                if(wordStarted){
                    break;
                }else{
                    left -= 1;
                    right -= 1;
                }
            }
        }
        return right - left;
    }
};


------------------------------------------------------------------------------------------------------------------------------
  
  class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        for(int i = s.length() - 1; i>=0; i--){
            if(int(s[i]) != 32){
                len += 1;
            }else{
                if(len > 0){
                    return len;
                }
            }
        }
        return len;
    }
};
