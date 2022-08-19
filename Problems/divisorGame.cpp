class Solution {
public:
    bool f(int n, int turnAlice){
        if(n == 1){
            return false;
        }
        bool ans = f(n-1, !turnAlice);
        int movesRemaining = n;
        for(int x = 1; x < n; x++){
            if(movesRemaining == 1 && n % x == 0){
                n = n - x;
                return ans = (true && turnAlice);
                
            }
            movesRemaining -= 1; 
        }
        // ans = false;
        return ans = !turnAlice;
    }
    
    bool divisorGame(int n) {
        return f(n, n % 2 != 0);
    }
};

-----------------------------------------------------------------------------------------------
  
  class Solution {
public:
    bool divisorGame(int n) {
        return n%2 ==0;
    }
};
