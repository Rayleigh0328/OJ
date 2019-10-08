template<typename T>
int binary_search_mono_inc_geq(
        const std::vector<T>& v, 
        int start, 
        int end, 
        const T& key
        )
{
    int mid ;
    while (start < end){
        if (start == end - 1) return (v[start] >= key ? start : -1);
        if (start == end - 2) {
            if (v[start] >= key) return start;
            else if (v[start + 1] >= key) return start + 1;
            else return -1;
        }
         
        mid = (start + end) / 2;
        if (v[mid] >= key) end = mid + 1;
        else start = mid + 1; 
    }
    return -1;
}

class Solution {
    int count(const vector<int>& a, int dist){
        int ans = 0;
        for (int i=0; i<a.size(); ++i){
            int pos = binary_search_mono_inc_geq(a, 0, i, a[i] - dist);
            if (pos != -1) ans += i - pos;
        }
        return ans;
    }

public:
    int smallestDistancePair(vector<int>& a, int k) {

        sort(a.begin(), a.end());

        int left = 0, right = a[a.size()-1] + 1; 
        int mid;
        while (left < right){
            if (left + 1 == right) return left; 
            if (left + 2 == right){
                if (count(a, left)>=k) return left;
                else return left + 1;
            }

            mid = (left + right) / 2;
            if (count(a, mid) >= k) right = mid + 1;
            else left = mid;
        }

        return 0;
    }
};

