class Solution {
public:
    int mySqrt(int x) {
        int start = 0;
        long int end = x;
        long int ans = -1;
        // int sq = x*x;
        while(start <= end){
            long int mid = start + (end - start) /2;
            long int sq = mid * mid;
            if(sq == x){
                return mid;
            }else if(sq < x){
                ans = mid;
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return ans;
    }
};
