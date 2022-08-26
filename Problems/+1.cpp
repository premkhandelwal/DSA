-----------------------------------------------------------------------Not working--------------------------------------------------------------------------
  
  
  class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int n = digits.size();
        if(digits[n -1] == 9){
            int i = n - 1;
            int j = n - 2;
            do{
                digits[i] = 0;
                i -=1;
                j -= 1;
                cout << i << endl;                
            }while(digits[i] == 9 && i>=0);
            // digits[j + 1] += 1;
        }else{
            digits[n-1] += 1;
        }
        if(carry){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

-----------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1; i >= 0; i--){
            if(digits[i] != 9){
                digits[i] += 1;
                return digits;
            }else{
                digits[i] = 0;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
