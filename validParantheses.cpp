class Solution {
public:
    bool isValid(string s) {
       stack<char> stac = {};
        unordered_map<char, char> bracketMap = {{')','('}, {'}', '{'}, {']' , '['}};
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stac.push(s[i]);
            }else{
                if(stac.empty()){
                    return false;
                }
                char popEle = stac.top();
                stac.pop();
                if(popEle != bracketMap[s[i]]){
                    return false;
                }
            }
        }
        if(stac.empty()){
            return true;
        }
        return false;
        
    }
};

-------------------------------------------------------------------------------------------------
  
  class Solution {
public:
    bool isValid(string s) {
        stack<char> stac = {};
        for(char& i:s){
            if(i == '('){
                stac.push(')');
            }else if(i == '['){
                stac.push(']');
            }else if(i == '{'){
                stac.push('}');
            }else if(stac.empty() || stac.top() != i){
                return false;
            }else{
                stac.pop();
            }
                
        }
        return stac.empty();
    }
};
