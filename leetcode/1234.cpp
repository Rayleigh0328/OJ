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
    
    bool check(int left, int right){
        for (int i=0;i<4;++i)
            if ((0<=left && left<n?cnt_left[left][i]:0) + (0<=right && right<n?cnt_right[right][i]:0) > target) return false;
        return true;
    }
    
    int get_ans(int left, int right){
        return right - left - 1;
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
        
        int ans = n;
        int left = -1, right = n+1;
        while (check(left+1, right)) ++left;
        // printf("left: %d\n", left);
        ans = min(ans, get_ans(left, right));
        while (left >= -1){
            --right;
            while (left >=-1 && !check(left, right)) --left;
            if (check(left, right)) ans = min(ans, get_ans(left, right));
        }
        
        return ans;
    }
};
