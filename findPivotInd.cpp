class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        int pre = 0;
        for(int i=0; i<nums.size(); i++){
            int rightSum = sum - pre - nums[i];
            if(rightSum == pre){
                return i;
            }
            pre += nums[i];
        }
        return -1;
    }
};
