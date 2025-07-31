class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>result;
        unordered_set<int>prev;
        unordered_set<int>curr;
        int n=arr.size();


        for(int i=0;i<n;i++){
            for(const int&x:prev){
                curr.insert(arr[i] |x);
                result.insert(arr[i] |x);
                
            }
            //inserting for first element
        curr.insert(arr[i]);
        result.insert(arr[i]);
        
        prev=curr;
        curr.clear();
        }
        return result.size();
    }
};

