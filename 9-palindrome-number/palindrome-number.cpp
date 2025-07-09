class Solution {
public:
    bool isPalindrome(int i) {
         int orig;
         long long rev=0;
         orig= i;
         while(i>0){
         rev=(rev*10)+i%10;
         i=i/10;
         }
         if(orig==rev){
            return true;
         }
         else{
            return false;
         }
         
         

        
    }
};