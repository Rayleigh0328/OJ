class Solution {
    
    bool is_equal(const vector<int> &x, const vector<int> &y){
        for (int i=0;i<x.size();++i)
            if (x[i] != y[i]) return false;
        return true;
    }

    bool is_complement(const vector<int> &x, const vector<int> &y){
        for (int i=0;i<x.size();++i)
            if (x[i] != (1-y[i])) return false;
        return true;
    }
    
    bool equal_or_complement(const vector<int> &x, const vector<int> &y){
        return is_equal(x,y) || is_complement(x,y);
    }
    
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int result = 0;
        int count = 0;
        for (int i=0;i<n;++i){
            count = 1;
            for (int j=i+1;j<n;++j)
                if (equal_or_complement(matrix[i],matrix[j])) ++count;
            if (count > result) result = count;
        }
        return result;
    }
};
