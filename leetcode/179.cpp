class Solution {
private:
    static bool cmp(string x, string y)
    {
        return x+y > y+x;
    }
    
    bool check_all_zero(vector<int>& a)
    {
        for (int i=0;i<a.size();++i)
            if (a[i] != 0) return false;
        return true;
    }
public:
    string largestNumber(vector<int>& nums) 
    {
        if (check_all_zero(nums)) return "0";
        vector<string> a;
        for (int i=0;i<nums.size();++i)
            a.push_back(to_string(nums[i]));
            
        sort(a.begin(), a.end(), cmp);
        
        string ans = "";
        for (int i=0; i<a.size();++i)
            ans += a[i];
        return ans;
    }
};