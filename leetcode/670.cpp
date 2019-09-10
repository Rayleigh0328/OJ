class Solution {
public:
    int get_max_pos(const vector<int>& v, int left, int right){
        int pos = left;
        for (int i=left; i<=right;++i)
            if (v[i]>v[pos]) pos = i;
        return pos;
    }
    int maximumSwap(int num) {
        // 2736 convert to vector [6,3,7,2] 
        vector<int>v;
        while (num > 0){
            v.push_back(num % 10);
            num /= 10;
        }
        for (int i=v.size()-1; i>=0;--i){
            int max_pos = get_max_pos(v,0,i);
            if (v[i] != v[max_pos]) {
                int tmp=v[i];
                v[i] = v[max_pos];
                v[max_pos]=tmp;
                break;
            }
        }
        int ans = 0;
        for (int i=v.size()-1;i>=0;--i)
            ans = ans * 10 + v[i];
        return ans;
    }
};
