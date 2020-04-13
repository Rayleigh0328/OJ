class Solution {
public:
    vector<string> stringMatching(vector<string>& a) {
        vector<string> result;
        for (int i=0;i<a.size();++i)
            for (int j=0;j<a.size();++j)
                if (i!=j && a[j].find(a[i]) != string::npos){
                    result.push_back(a[i]);
                    break;
                }
        return result;
    }
};
