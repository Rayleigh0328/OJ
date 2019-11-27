class Solution {
    
public:
    int minMoves(vector<int>& a) {
        if (a.size() < 2) return 0;
        sort(a.begin(), a.end());
        int n = a.size();
        int result = 0;
        int diff=0;
        for (int i=0;i<n-1;++i){
            diff = a[i+1] + diff - a[i];
            result += diff;
            // printf("a[i]: %d, diff: %d, result: %d\n", a[i], diff, result);
        }
        return result;
    }
};
