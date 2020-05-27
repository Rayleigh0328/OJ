class Solution {
    const int mode = 1000000007;
    const int inf = (1<<28);
public:
    int sumSubarrayMins(vector<int>& A) {
        
        const int n = A.size();
        vector<int> a;
        a.push_back(-inf);
        for (auto x : A) a.push_back(x);
        a.push_back(-inf + 1);
        
        vector<int> st;
        st.push_back(0);
        
        int result = 0;
        
        for(int i=1;i<n+2;++i){
            while (a[i] <= a[st.back()]){
                int index = st.back();
                // printf("pop a[%d] = %d\n", index, a[index]);
                st.pop_back();
                result = (result + static_cast<long long>(a[index]) * (i-index) * (index-st.back())) % mode;
            }
            st.push_back(i);
        }
        
        return result;
    }
};
