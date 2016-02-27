class Solution {
private:
    bool **flag;
    int n, m;
    
    bool solve(vector<vector<char>>&a, string &word, int x, int y, int pos)
    {
        if (pos == word.size()) return true;
        // out of board check
        if (x < 0) return false;
        if (x >=n) return false;
        if (y < 0) return false;
        if (y >=m) return false;
        //cout << x << " " << y << " " << pos << endl;
        if (!flag[x][y] && a[x][y] == word[pos])
        {
             
            flag[x][y] = true;
            bool ans = false;
            ans = ans || solve(a,word, x-1,y,pos+1) || solve(a,word,x+1,y,pos+1) || solve(a,word,x,y-1,pos+1) || solve(a,word,x,y+1,pos+1);
            flag[x][y] = false;
            return ans;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& a, string word) {
        if (word.size() == 0) return true;
        n = a.size();
        if (n==0) return false;
        m = a[0].size();
        if (m==0) return false;
        
        flag = new bool* [n];
        for (int i=0;i<n;++i)
            flag[i] = new bool [m];
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                flag[i][j] = false;
        
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                if (solve(a,word, i,j,0)) return true;
        return false;
    }
};