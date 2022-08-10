class Solution {
public:
    int fib(int n) {
        if(n == 0){
            return 0;
        }if(n == 1){
            return 1;
        }
        return fib(n - 1) + fib(n - 2);
    }
};

-------------------------------------------------------------------
  
  class Solution {
public:
    int fib(int n) {
        if(n== 0){
            return 0;
        }
        int prev = 1;
        int prev2 = 0;
        for(int i = 0; i < n - 1; i++){
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
