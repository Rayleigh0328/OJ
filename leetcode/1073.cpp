class Solution {
    int get_element(const vector<int>& v, int pos){
        if (pos < v.size()) return v[pos];
        return 0;
    }
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        vector<int> x;
        for (int i=arr1.size()-1; i>=0;--i) x.push_back(arr1[i]);
        vector<int> y;
        for (int i=arr2.size()-1; i>=0;--i) y.push_back(arr2[i]);
        int carry = 0;
        int pos = 0;
        do {
            int tmp = get_element(x, pos) + get_element(y, pos) + carry;
            ++pos;
            if (tmp == 0){
                ans.push_back(0);
                carry = 0;
            }
            else if (tmp == 1){
                ans.push_back(1);
                carry = 0;
            }
            else if (tmp == 2){
                ans.push_back(0);
                carry = -1;
            }
            else if (tmp == 3){
                ans.push_back(1);
                carry = -1;
            }
            else if (tmp == -1){
                ans.push_back(1);
                carry = 1;
            }
        }
        while (carry != 0 || pos < arr1.size() || pos < arr2.size() );
        while (ans[ans.size()-1]==0 && ans.size() > 1) ans.pop_back();
        vector<int> result;
        for (int i=ans.size()-1;i>=0;--i) result.push_back(ans[i]);
        return result;
    }
};
