class Solution {
private:
    typedef pair<int, int> pos_ind;
    
    string x,y,z;
    set<pos_ind> set1;
    set<pos_ind> set2;
    
    void solve(int z_pos, set<pos_ind>& prev, set<pos_ind>&next)
    {
        next.clear();
        for (set<pos_ind>::iterator it = prev.begin(); it != prev.end(); ++it)
        {
            int x_pos = it->first;
            int y_pos = it->second;
            
            if (x_pos + 1 < x.size() && x[x_pos+1] == z[z_pos]) next.insert(pos_ind(x_pos+1, y_pos));
            if (y_pos + 1 < y.size() && y[y_pos+1] == z[z_pos]) next.insert(pos_ind(x_pos, y_pos+1));
        }
    }
    
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        x = s1;
        y = s2;
        z = s3;
        if (z.size() != x.size() + y.size()) return false;
        set2.clear();
        set1.clear();    
        set1.insert(pos_ind(-1,-1));
        
        for (int i=0;i<s3.size();++i)
            if (i % 2 == 0) 
                solve(i,set1, set2);
            else 
                solve(i,set2, set1);
     
        if (s3.size() % 2 == 0)
            return !set1.empty();
        else 
            return !set2.empty();
    }
};