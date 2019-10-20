class Solution {
    static const int MAX_SIZE=100005;
    vector<char> i_to_c{'Q','W','E','R'};
    unordered_map<char,int> c_to_i{
        {'Q',0},{'W',1},{'E',2},{'R',3}
    };
    int cnt_left[MAX_SIZE][4];
    int cnt_right[MAX_SIZE][4];
    int n;
    int target;
    
    bool check(int len){
        int right;
        bool good;
        for (int left=0;left+len-1<n;++left){
            right = left + len -1;
            good = true;
            for (int i=0;i<4;++i)
                if ((left>0?cnt_left[left-1][i]:0) + (right<n-1?cnt_right[right+1][i]:0) > target) good = false;
            if (good) return true;
        }
        return false;
    }
    
public:
    int balancedString(string s) {
        n = s.length();
        ++cnt_left[0][c_to_i[s[0]]];
        for (int i=1;i<s.size();++i) {
            for (int j=0;j<4;++j) cnt_left[i][j] = cnt_left[i-1][j];
            ++cnt_left[i][c_to_i[s[i]]];
        }
        ++cnt_right[n-1][c_to_i[s[n-1]]];
        for (int i=s.size()-2; i>=0; --i) {
            for (int j=0;j<4;++j) cnt_right[i][j] = cnt_right[i+1][j];
            ++cnt_right[i][c_to_i[s[i]]];
        }
        target = n/4;
        if (cnt_right[0][0] == target && cnt_right[0][1] == target && cnt_right[0][2] == target && cnt_right[0][3] == target) return 0;
        
        int left = 1, right = n+1, mid;
        while (left < right){
            if (left + 1== right) return left;
            if (left + 2 == right){
                if (check(left)) return left;
                return left+1;
            }
            mid = (left + right) / 2;
            if (check(mid)) right = mid + 1;
            else left = mid + 1;
        }
        return -1;
    }
};
