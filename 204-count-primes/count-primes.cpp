class Solution {
public:
    int countPrimes(int n) {
        vector<bool>prime(n+1,true);
         int cnt=0;
        prime[0]=prime[1]=0;
        for(int i=2;i<n;i++){
            if(prime[i]){
                cnt++;
                for(int j=2*i;j<n;j=j+i){
                    prime[j]=0;
                }
            }

        }
          return cnt;
    }
};