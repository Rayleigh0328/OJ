class Solution {
    struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs>rhs;}
};

public:
    vector<int> prevPermOpt1(vector<int>& A) {
        vector<int> a(A);
        set<int, classcomp> tail;
        for (int i=a.size()-1; i>=0;--i){
            tail.insert(a[i]);
            if (tail.upper_bound(a[i]) != tail.end()){
                int target = *tail.upper_bound(a[i]);
                // cout << "swap " << a[i] << " "<< target << endl;
                int j;
                for(j=i+1; j<a.size();++j)
                    if (a[j] == target) break;
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
                break;
            }
        }
        return a;
    }
};
