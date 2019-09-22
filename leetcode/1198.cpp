
template<typename T>
int binary_search_mono_inc_eq(
        const std::vector<T>& v, 
        int start, 
        int end, 
        const T& key
        )
{
    int mid ;
    while (start < end){
        if (start == end - 1) return (v[start] == key ? start : -1);
         
        mid = (start + end) / 2;
        if (v[mid] == key) return mid;
        if (v[mid] < key) start = mid + 1;
        else end = mid; 
    }
    return -1;
}

class Solution {
    bool appear_in_all(int x, const vector<vector<int>>& m){
        for (int i=1;i<m.size();++i)
            if (binary_search_mono_inc_eq(m[i], 0, m[i].size(), x) == -1) return false;
        return true;
    }
    
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        if (mat.size() == 1) {
            if (mat[0].empty()) return -1;
            else return mat[0][0];
        }
        for (int i=0;i<mat[0].size();++i)
            if (appear_in_all(mat[0][i], mat))
                return mat[0][i];
        return -1;
    }
};

