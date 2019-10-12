class Solution {
    void flip(vector<int> &a, int len){
        vector<int> tmp(len);
        for (int i=0;i<len;++i)
            tmp[i] = a[len-1-i];
        for (int i=0;i<len;++i)
            a[i] = tmp[i];
    }
public:
    vector<int> pancakeSort(vector<int>& a) {
        vector<int> ans;
        for (int i=a.size()-1; i >= 0; --i){
            // printf("try pos %d\n", i);
            int max_pos = i;
            for (int j=i-1; j>=0; --j)
                if (a[j] > a[max_pos]) max_pos = j;
            // printf("max_pos is %d\n", max_pos);
            if (max_pos < i){
                if (max_pos > 0) ans.push_back(max_pos + 1);
                flip(a,max_pos+1);
                if (i > 0) ans.push_back(i+1);
                flip(a, i+1);
            }
        }
        // for (int i=0;i<a.size();++i) printf("%d ", a[i]); cout << endl;
        return ans;
    }
};
