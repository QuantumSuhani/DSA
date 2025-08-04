class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>basket;
        int maxlength=0;
        int n=fruits.size();
        int s=0;

        for(int e=0;e<n;e++){
            basket[fruits[e]]++;

           while(basket.size()>2){
              basket[fruits[s]]--;
             if(basket[fruits[s]]==0){
            basket.erase(fruits[s]);
            }
         s++;
     }

        maxlength=max(maxlength,e-s+1);
        }

return maxlength;
}
};
      