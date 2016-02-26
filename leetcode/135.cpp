class Solution {
public:
    int candy(vector<int>& a) 
    {
        if (a.empty()) return 0;
        int *f = new int [a.size()];
        f[0] = 1;
        for (int i=1;i<a.size();++i)
            f[i] = a[i]>a[i-1] ? f[i-1] + 1 : 1;
            
        //cout << "f: " ;
        //for (int i=0;i<a.size();++i)
        //    cout << f[i] << " ";
        //cout << endl;
        
        int *g = new int [a.size()];
        g[a.size()-1] = 1;
        for (int i=a.size()-2;i>=0;--i) 
            g[i] = a[i]>a[i+1] ? g[i+1] + 1 : 1;
        
        //cout << "g: " ;
        //for (int i=0;i<a.size();++i)
        //    cout << g[i] << " ";
        //cout << endl;
        
        int ans = 0;
        for (int i=0;i<a.size();++i)
            ans += max(f[i],g[i]);
        return ans;
    }
};