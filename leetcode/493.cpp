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

template<typename T>
vector<T> discretize(const vector<T> &a){
    set<T> s;
    for (auto x : a) s.emplace(x);
    vector<T> ans;
    for (auto x : s) ans.push_back(x); 
    return ans;
}

class BinaryIndexedTree{
    // note that binary indexed tree is 1 indexed
    vector<int> v;

public:
    void print(){
        for (int i=1; i<v.size();++i)
            cout << v[i] << " ";
        cout << endl;
    }

    // init with all 0s
    BinaryIndexedTree(int size) {
        v = vector<int>(size+1, 0);
    }

    // init with specific array
    BinaryIndexedTree(const vector<int> &a) {
        v=vector<int>(a.size()+1, 0);
        for(int i=0;i<a.size();++i) v[i+1] = a[i];
        for (int i=1;i<v.size();++i){
            int j = i + low(i); 
            if (j < v.size()) v[j] += v[i];
        }
    }

    int low(int k){
        return (k & -k);
    }

    int find_prefix_sum(int len){
        int result = 0;
        while (len > 0){
            result += v[len];
            len -= low(len);
        }
        return result;
    }

    void update(int k, int delta){
        // update a[k] to a[k] + delta
        // note this k is the index in the orignal array
        ++k;
        while (k < v.size()){
            v[k] += delta;
            k += low(k);
        }
    }

    int get_interval_sum(int left, int right){
        // note that left, right are index in original array
        return find_prefix_sum(right+1) - find_prefix_sum(left );
    }

};

class Solution {
   int get_index(const vector<long long>& v, long long value){
       return binary_search_mono_inc_geq(v, 0, v.size(), value);
   }

public:
    int reversePairs(vector<int>& a) {

        vector<long long> tmp_v;
        for (auto x : a) tmp_v.push_back(x);
        vector<long long> discretized = discretize(tmp_v);
        
        BinaryIndexedTree bit(discretized.size());
        
        int ans = 0;
        for (int i=0; i<tmp_v.size(); ++i){
            long long lb = tmp_v[i] * 2 + 1;
            int pos = get_index(discretized, lb);
            if (pos != -1){
                ans += bit.get_interval_sum(pos, discretized.size()-1);
            }
            bit.update(get_index(discretized, tmp_v[i]), 1);
        }
        return ans;
    }
};

