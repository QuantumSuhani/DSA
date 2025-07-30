class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxvalue=*max_element(nums.begin(),nums.end());//finding maximum value from the array
        int streak=0;//currentlength of maximum value is 0
        int result=0;//initialising result with 0
        for(int num:nums){
            if(num==maxvalue){
                streak++;//updating streak value when value is equal to maxvalue
                result=max(result,streak);//finding max between result and streak and upadating result
            }
            else{
                streak=0;//if value is different  
            }
        }
        return result;
    }
};