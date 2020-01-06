class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        int sum = 0;
        for (int i=0;i<n-1;++i){
            sum += i;
            result.push_back(i);
        }
        result.push_back(-sum);
        return result;
    }
};
