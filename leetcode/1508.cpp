class Solution {
    
    const int mode = 1000000007;
    
public:
    int rangeSum(vector<int>& a, int n, int left, int right) {
        vector<int> b;
        int sum;
        for (int i=0;i<a.size();++i){
            sum = 0;
            for (int j=i;j<a.size();++j) {
                sum += a[j];
                b.push_back(sum);
            }
        }
        
        sort(b.begin(), b.end());
        // for (auto x : b) printf("%d ", x); printf("\n");
        int result = 0;
        for (int i=left-1;i<right;++i)
            result = (result + b[i]) % mode;
        return result;
    }
};
