class Solution {
    
    const double eps = 1e-8;
    
    void divide(string s, vector<string> &v){
        int pos = s.find('.');
        if (pos == string::npos){
            v = {s,"0","0"};
            return;
        }
        v.push_back(s.substr(0,pos));
        s = s.substr(pos+1);
        pos = s.find("(");
        if (pos == string::npos){
            v.push_back(s);
            v.push_back("0");
            return;
        }
        v.push_back(s.substr(0,pos));
        v.push_back(s.substr(pos+1));
        v[2].pop_back();
    }
    
    double convert(const vector<string>& a){
        double result = stod(a[0]);
        if (!a[1].empty()) result += stod(a[1]) * pow(0.1, a[1].size());
        if (!a[2].empty()) {
            double q = pow(0.1, a[2].size());
            double k = stod(a[2]) * q;
            result += pow(0.1, a[1].size()) * k / (1-q);
        }
        return result;
    }
    
public:
    bool isRationalEqual(string s, string t) {
        vector<string> a, b;
        divide(s, a);
        divide(t, b);
        return abs(convert(a) - convert(b)) < eps;    
    }
};
