class Solution {
    vector<double> getvalidoperation(double a,double b){
        vector<double> validoperation;
        validoperation.push_back(a+b);
        validoperation.push_back(a-b);
        validoperation.push_back(b-a);
        validoperation.push_back(a*b);

        if(abs(b)>FLT_EPSILON)
            validoperation.push_back(a/b);
        if(abs(a)>FLT_EPSILON)
            validoperation.push_back(b/a);

        return validoperation;  
    }

    bool isPossible(vector<double>& arr) {
        int n = (int)arr.size();
        if(n == 1){
            return abs(24.0 - arr[0]) <= FLT_EPSILON;
        }

        for(int fn=0; fn<n; fn++){
            for(int sn=0; sn<n; sn++){
                if(sn == fn) continue;

                double firstnumber = arr[fn];
                double secondnumber = arr[sn];
                vector<double> validoperations = getvalidoperation(firstnumber,secondnumber);

                for(double validoperation : validoperations) {
                    vector<double> nextarr;
                    nextarr.push_back(validoperation);

                    for(int i=0; i<n; i++){
                        if(i==fn || i==sn) continue;
                        nextarr.push_back(arr[i]);
                    }

                    if(isPossible(nextarr)) return true;
                }
            }
        }
        return false;
    }  
    
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> arr(cards.begin(), cards.end());
        return isPossible(arr);
    }
};
