class Solution {
    string s;
    int n;
    vector<vector<int>> schedule;
    
    void print_schedule(){
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j)
                printf("%d ",schedule[i][j]);
            cout << endl;
        }
    }
    
    int solve(int left, int right){
        // printf("finish solve %d to %d\n", left, right);

        if (left >= right) 
            return (schedule[left][right]=0);
        
        if (schedule[left][right] != -1)
            return schedule[left][right];
        
        schedule[left][right] = 1 + min(solve(left+1,right), solve(left, right-1));
        if (s[left] == s[right]) schedule[left][right] = min(schedule[left][right], solve(left+1, right-1));
        // printf("finish solve %d to %d\n", left, right);
        // print_schedule();
        return schedule[left][right];
    }
    
public:
    bool isValidPalindrome(string input_s, int k) {
        s = input_s;
        n = s.length();   
        schedule = vector<vector<int>>(n, vector<int>(n, -1));
        
        solve(0,n-1);
        
        return (schedule[0][n-1] <= k);
    }
};
