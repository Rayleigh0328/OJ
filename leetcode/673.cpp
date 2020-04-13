template <typename T>
class BinaryIndexedTree{
    vector<T> v;
public:
    BinaryIndexedTree():BinaryIndexedTree(0){}
    BinaryIndexedTree(int size) {
        v = vector<T>(size, 0);
    }
    int low(int k){
        return (k & -k);
    }
    T find_prefix_sum(int len){
        int result = 0;
        while (len > 0){
            result += v[len];
            len -= low(len);
        }
        return result;
    }
    void update(int k, int delta){
        // update a[k] to a[k] + delta
        while (k < v.size()){
            v[k] += delta;
            k += low(k);
        }
    }
};

class Solution {    
    const int MAX_SIZE = 2010;   
    struct BucketType{
        int min_element;
        BinaryIndexedTree<int> bit;
        
        BucketType(int min, int bit_size){
            min_element = min;
            bit = BinaryIndexedTree<int>(bit_size);
        }
        
        bool operator<(const BucketType &other) const{
            return min_element < other.min_element;
        }
    };
    
    unordered_map<int, int> discretize(vector<int>&a){
        set<int> s;
        for (int x : a) s.emplace(x);
        unordered_map<int, int> result;
        int index = 1;
        for (int e : s)
            result[e] = ++index;
        return result;
    }
    
public:
    int findNumberOfLIS(vector<int>& a) {       
        if (a.empty()) return 0;        
        unordered_map<int, int> mp = discretize(a);      
        vector<BucketType> h;
        h.push_back(BucketType(1,MAX_SIZE));
        h[0].bit.update(1,1);
        for (auto x : a){
            auto it = lower_bound(h.begin(), h.end(), BucketType(mp[x],0));
            if (it == h.end()){
                int tmp = h.back().bit.find_prefix_sum(mp[x]-1);
                h.push_back(BucketType(mp[x], MAX_SIZE));
                h.back().bit.update(mp[x], tmp);
            }
            else {
                it->min_element = mp[x];
                it->bit.update(mp[x], (it-1)->bit.find_prefix_sum(mp[x]-1));
            }
        }      
        return h.back().bit.find_prefix_sum(MAX_SIZE-1);
    }
};
