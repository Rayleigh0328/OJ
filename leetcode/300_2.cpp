template<typename T>
int binary_search_mono_inc_less_than(
        const std::vector<T>& v, 
        int start, 
        int end, 
        const T& key
        )
{
    int mid ;
    while (start < end){
        if (start == end - 1) return (v[start] < key ? start : -1);
        if (start == end - 2) {
            if (v[start+1] < key) return start + 1;
            else if (v[start] < key) return start;
            else return -1;
        }
         
        mid = (start + end) / 2;
        if (v[mid] < key) start = mid;
        else end = mid; 
    }
    return -1;
}

class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        vector<int> h;
        h.push_back(-(1<<30));
        int pos;
        int ans = 0;
        for (auto x : a){
            pos = binary_search_mono_inc_less_than(h, 0, h.size(), x);
            ans = max(ans, pos+1);
            if (pos == h.size() -1) h.push_back(x);
            else if (x < h[pos+1]) h[pos+1] = x;
        }
        return ans;
    }
};
