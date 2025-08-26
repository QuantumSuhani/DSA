class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n=dimensions.size();
        int maxdiagonal=0;
        int maxarea=0;

        for(int i=0;i<n;i++){
            int l=dimensions[i][0];
            int w=dimensions[i][1];
            int diagonal= l*l+w*w;
            int area=l*w;


            if(diagonal>maxdiagonal){
                maxdiagonal=diagonal;
                maxarea=area;
            }
            else if(maxdiagonal==diagonal){
               maxarea= max(maxarea,area);

            }
        }
        return maxarea;

        
    }
};