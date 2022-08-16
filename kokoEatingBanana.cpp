class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        
        int minHours = high;
        while(low <= high){
            int mid = high + (low - high)/2;
            int hours = 0;
            for(auto i: piles){
                // cout<<i<<" ";
                hours += (i/mid)+((i % mid) != 0);
            }
            // cout<<endl;
            if(hours <= h){
                minHours = min(minHours, mid);
                high = mid - 1; 
            }else{
                low = mid + 1;
            }
        }
        return minHours;
    }
};
