class Solution {

    string add(const string& a, const string& b){
        int carry = 0;
        int pos = 0;
        int tmp;
        string result="";
        while (pos < a.size() || pos < b.size() || carry!=0){
            tmp = (pos<a.size()?a[pos] - '0':0) + (pos<b.size()?b[pos] - '0':0) + carry;
            result.push_back('0' + tmp%10);
            carry = tmp/10;
            ++pos;
        }
        return result;
    }
    
    string times(const string &a, int b){
        string result = "";
        int carry = 0;
        int pos = 0;
        int tmp;
        while (pos < a.size() || carry!=0){
            tmp = (pos<a.size()?a[pos]-'0':0) * b + carry;
            result.push_back('0' + tmp%10);
            carry = tmp/10;
            ++pos;
        }
        return result;
    }
    
    string solve(const string &a, const string &b){
        string result = "0";
        for (int i=0;i<b.size();++i){
            string row = string(i,'0') + times(a,b[i]-'0');
            result = add(result, row);
        }
        while (result.back() == '0' && result.size() > 1) result.pop_back(); 
        return result;
    }
    
public:
    string multiply(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string result = solve(a, b);
        reverse(result.begin(), result.end());
        return result;
    }
};
