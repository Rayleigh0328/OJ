template <typename T>
class BinaryIndexedTree{
    // NOTE: that binary indexed tree is 1 indexed
    // the corresponding array a is 0 indexed
    vector<T> v;

public:
    // init with all 0s
    BinaryIndexedTree(int size) {
        v = vector<T>(size+1, 0);
    }

    // init with specific array
    BinaryIndexedTree(const vector<T> &a) {
        v=vector<T>(a.size()+1, 0);
        for(int i=0;i<a.size();++i) v[i+1] = a[i];
        for (int i=1;i<v.size();++i){
            int j = i + low(i);
            if (j < v.size()) v[j] += v[i];
        }
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
        // note this k is the index in the orignal array
        ++k;
        while (k < v.size()){
            v[k] += delta;
            k += low(k);
        }
    }

    T get_interval_sum(int left, int right){
        // note that left, right are index in original array
        return find_prefix_sum(right+1) - find_prefix_sum(left );
    }

};


class Solution {
    
public:
    string minInteger(string s, int k) {
        
        vector<vector<int>> pos(10);
        const int n = s.size();
        for (int i=n-1;i>=0;--i)
            pos[s[i]-'0'].push_back(i);
        
        BinaryIndexedTree<int> bit = BinaryIndexedTree<int>(n+1);
        string result = s;
        for (int i=0;i<n;++i){
            for (int d=0;d<10;++d){
                if (pos[d].empty()) continue;
                int p = pos[d].back();
                int required = p + bit.get_interval_sum(p+1,n-1) - i;
                if (k >= required){
                    k -= required;
                    pos[d].pop_back();
                    bit.update(p, 1);
                    result[i] = '0' + d;
                    break;
                }
            }
        }
        
        return result;
    }
};
