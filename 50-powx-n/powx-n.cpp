class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        long binform=n;
        if(n<0){
            x=1/x;
            binform=-binform;
        }
        while(binform>0){
             if(binform%2==1){
                ans=ans*x;
             }
             x=x*x;
             binform=binform/2;
        }
       
return ans;
        
    }
};