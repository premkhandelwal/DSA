class Solution {
public:
    int romanToInt(string s) {
        map<char, int> romanChar; 
        romanChar['I'] =  1;
        romanChar['V'] = 5;
        romanChar['X'] = 10;
        romanChar['L'] =  50;
        romanChar['C'] =  100;
        romanChar['D'] = 500;
        romanChar['M'] =  1000;
        int num = 0;
        int i =0;
        while(i<s.length()){
            if(s[i] == 'I' && (i + 1 <= s.length() - 1) && (s[i + 1] == 'V' || s[i+1] == 'X')){
                num += romanChar[s[i+1]] - 1; 
                i += 2;
            }else if(s[i] == 'X' && (i + 1 <= s.length() - 1) && (s[i + 1] == 'L' || s[i+1] == 'C')){
                num += romanChar[s[i+1]] - 10; 
                i += 2;

            }else if(s[i] == 'C' && (i + 1 <= s.length() - 1) && (s[i + 1] == 'D' || s[i+1] == 'M')){
                num += romanChar[s[i+1]] - 100;  
                cout<< romanChar[s[i+1]] - 100<<endl;
                i += 2;
 
            }else{
                                cout<< romanChar[s[i+1]] - 100<<endl;

                // cout<<num<<endl;
                // cout<<romanChar[s[i+1]]<<endl;
                num += romanChar[s[i]];
                i++;
            }
            
        }
    return num;
    }
};


--------------------------------------------------------------------------------------------------------------------------------------------------
    Approach2
    
    class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanChar = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
        int num = 0;
        for(int i = 0; i < s.length(); i++){
            if(romanChar[s[i]] < romanChar[s[i + 1]]){
                num -= romanChar[s[i]];
            }else{
                num += romanChar[s[i]]; 
            }
        }
        return num;
    }
};
