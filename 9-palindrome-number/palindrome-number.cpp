class Solution {
public:
    bool isPalindrome(int i) {
         int orig;
         long long rev=0;//long long keyword is used to hold values that int cannot store
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