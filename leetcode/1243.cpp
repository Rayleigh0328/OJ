class Solution {
public:
    vector<int> transformArray(vector<int>& a) {
        int n = a.size();
        if (n <= 2) return a;
        vector<int> b(a);
        
        bool changed=true;
        while (changed){
            changed = false;
            b[0] = a[0];
            b[n-1] = a[n-1];
            for (int i=1;i<n-1;++i){
                if (a[i]>a[i-1] && a[i] > a[i+1]) {b[i]=a[i]-1;changed=true;}
                else if (a[i]<a[i-1] && a[i] < a[i+1]){b[i]=a[i]+1;changed=true;}
            }
            a = b;
        }
        return b;
    }
};
