class Solution {
    
    const long long inf = (1LL<<60);
    
public:
    int minDifference(vector<int>& input) {
        
        vector<long long> a;
        for (auto x : input) a.push_back(x);
        
        if (a.size() <= 4) return 0; 
        sort(a.begin(), a.end());
        // for (auto x : a) printf("%d ", x); printf("\n");
        
        long long result = inf;
        // cout << "result:" << result << endl;
        for (int left=0;left<=3;++left){
            result = min(result, a[a.size()-4+left] - a[left]);
        }
        
        // int result = inf;
        // // change a[0], a[1], a[2]  ==>  a[3]
        // result = min(result, a.back() - a[3]);
        // // change a[size-1], a[size-2], a[size -3] to a[size - 4];
        // result = min(result, a[a.size()-4] - a[0]);
        
        return result;
    }
};
