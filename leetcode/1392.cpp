class Solution {
public:
    string longestPrefix(string p) {
        p.push_back(-1);
        int m = p.length();

        // construct function phi
        vector<int> phi(m);
        int i = 0, j = -1;
        phi[0] = -1;
        while (i < m-1){
            if (p[i+1] == p[j+1]) phi[++i] = ++j;
            else if (j >= 0) j = phi[j];
            else phi[++i] = -1;
        }
        
        // for (auto x : phi) cout << x << " "; cout << endl;
        
        return p.substr(0,phi[m-2]+1);
    }
};
