class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int i=2;//first two elemrnts are always included
        int n= nums.size();
        if(n<=2){//if number of elements are 2 or less then 2 
        return n;
        }
        for(int j=2;j<n;j++){
            if(nums[j]!=nums[i-2]){
                nums[i]=nums[j];
                i++;

            }
        }
        return i;


    }
};