template<typename T>
void radix_sort(vector<T>& a, int base){
    if (a.empty()) return ;
    
    // use max to determine number of rounds
    T max_element = a[0];
    for (int i=1; i<a.size(); ++i)
        if (a[i] > max_element) max_element = a[i];
    int round = 0;
    while (max_element > 0){
        max_element /= base;
        ++round;
    }
    vector<T> cp(a.size());
    vector<int> count(base);
    vector<int> pos(base);
    T tail = 1;
    for (int rd=1; rd<=round;++rd, tail*=base){
        // copy a to array cp
        for (int i=0; i<a.size(); ++i) cp[i] = a[i];
        // reset then calculate count
        for (int i=0; i<base; ++i) count[i] = 0;
        for (int i=0; i<cp.size();++i) ++count[cp[i] / tail % base];
        // calculate pos based on count
        pos[0] = 0;
        for (int i=1; i<base; ++i) pos[i] = pos[i-1] + count[i-1];
        // put element into a
        for (int i=0; i<cp.size();++i)
            a[ pos[cp[i]/tail%base]++ ] = cp[i];
    }
}


class Solution {
    
public:
    int maximumGap(vector<int>& nums) {
        vector<long long> a;
        for (auto x : nums) a.push_back(x);
        radix_sort(a,100);
        int ans = 0;
        for (int i=1;i<a.size();++i)
            if (a[i] - a[i-1] > ans) ans = a[i]-a[i-1];
        return ans;
    }
};
