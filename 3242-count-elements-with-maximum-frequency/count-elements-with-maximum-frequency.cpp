class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int>count(101);
        int maxfreq=0;
        int total=0;
        for(int &num:nums){
            count[num]++;

            int freq=count[num];
            if(freq>maxfreq){
                 maxfreq=freq;
                 total=maxfreq;
            }
            else if(freq==maxfreq){
                total=total+maxfreq;

            }
        }
            return total;
        }
    };