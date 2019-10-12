class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& a) {
        vector<int> cp(a.size());
        vector<int> pos(2);
        pos[0] = 0;
        pos[1] = 1;
        
        int type;
        for (int i=0;i<a.size();++i){
            type = (a[i] & 1);
            cp[pos[type]] = a[i];
            pos[type] += 2;
        }
        
        return cp;
    }
};
