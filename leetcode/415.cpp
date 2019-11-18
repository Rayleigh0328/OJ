class Solution {
public:
    string addStrings(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string result;
        int pos = 0, carry = 0;
        while (pos < a.size() || pos < b.size() || carry > 0){
            int ans = (pos<a.size()?a[pos] - '0':0) + (pos<b.size()?b[pos]-'0':0) + carry;
            carry = ans / 10;
            result.push_back(ans%10+'0');
            ++pos;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
