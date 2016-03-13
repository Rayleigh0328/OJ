class Solution {
public:
    int compareVersion(string s1, string s2) {
        string tmp1, tmp2;
        int pos1, pos2;
        int n1, n2;
        while (!s1.empty() || !s2.empty())
        {
            pos1 = s1.find_first_of('.');
            pos2 = s2.find_first_of('.');
            if (pos1 == string::npos) 
            {
                tmp1 = s1; 
                s1 = "";
            }
            else
            {
                tmp1 = s1.substr(0,pos1);
                s1 = s1.substr(pos1+1);
            }
            if (pos2 == string::npos)
            {
                tmp2 = s2;
                s2 = "";
            }
            else
            {
                tmp2 = s2.substr(0,pos2);
                s2 = s2.substr(pos2+1);
            }
            
            n1 = tmp1.empty()?0:stoi(tmp1);
            n2 = tmp2.empty()?0:stoi(tmp2);
            
            if (n1 < n2) return -1;
            else if (n1 > n2) return 1;
        }
        return 0;
    }
};