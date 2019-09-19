template<typename T>
std::vector<std::vector<T>>* construct_sparse_table(const std::vector<T>& v, T (*select)(T x, T y)){
    int n = v.size();
    std::vector<std::vector<T>> &f = *(new std::vector<std::vector<T>>);
    f.push_back(std::vector<T>(n, 0));
    for (int i=0;i<n;++i) f[0][i] = v[i];
    for (int k=1; (1<<k)<=n; ++k){
        f.push_back(std::vector<T>(n,0));
        for (int i=0;i<n;++i) 
            if (i + (1<<(k-1)) < n)
                f[k][i] = select(f[k-1][i], f[k-1][i+(1<<(k-1))]);
            else 
                f[k][i] = f[k-1][i];
        // std::cout << "f["  << k << "]: " << std::endl;
        // for (auto x : f[k]) std::cout << x << " ";
        // std::cout << std::endl;
    }
    return &f;
}

template<typename T>
T rmq(T (*select)(T x, T y), const std::vector<std::vector<T>>& f, int left, int right){
    int k=0;
    while ((1<<k) <= (right - left + 1)) ++k;
    --k;
    return select(f[k][left], f[k][right - (1<<k) + 1]);
}

template<typename T>
T select_min(T x, T y){
    if (x < y) return x;
    return y;
}

template<typename T>
T select_max(T x, T y){
    if (x > y) return x;
    return y;
}



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        vector<vector<int>>& f = *construct_sparse_table(nums, select_max);
        for (int i=0; i<nums.size();++i)
        	if (i + k -1 < nums.size())
        		ans.push_back( rmq(select_max, f, i, i+k-1) );
        return ans;
    }
};










