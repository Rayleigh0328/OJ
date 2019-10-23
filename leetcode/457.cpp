class Solution {
    
    bool dfs(int k, const vector<int>& a, vector<int>& color){
        // cout << "dfs: " << k << endl;
        // for (int i=0;i<a.size();++i) cout << color[i] <<" "; cout << endl;
        color[k] = 1;
        int next = (k + a[k])%a.size(); 
        bool result = false;
        if (color[next] == 1 && next != k) result = true;
       
        if (color[next] == 0 && a[next] > 0) 
            result = result || dfs(next,a,color);
        color[k] = 2;
        return result;
    }
    
    bool check(const vector<int>& a){
        vector<int> color(a.size(),0);
        for (int i=0;i<a.size();++i) 
            if (a[i] >= 0 && color[i]==0) 
                if (dfs(i,a,color)) return true;
        return false;
    }
    
public:
    bool circularArrayLoop(vector<int>& a) {
        int n = a.size();
        vector<int> b(n);
        for (int i=0;i<n;++i) b[i] = -a[n-1-i];
        return check(a) || check(b);
    }
};
