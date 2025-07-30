class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxvalue=nums[0];
        int result=0;
        int streak=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxvalue){
                maxvalue=nums[i];

            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxvalue){
                streak++;
            if(streak>result){
                result=streak;
            }
            }
            else{
                streak=0;
            }

        }
     return result;
    }
};