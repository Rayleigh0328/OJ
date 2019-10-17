class Solution {
    
public:
    vector<int> majorityElement(vector<int>& nums) {
        int m1, m2;
        int count1=0, count2=0;
        
        for (auto x : nums){
            if (x == m1) {
                ++count1;
            }
            else if (x == m2){
                ++count2;
            }
            else if (count2 == 0){
                m2 = x;
                count2 = 1;
            }
            else if (count1  == 0){
                m1 = x;
                count1 = 1;
            }
            else {
                --count1;
                --count2;
            }
        }
        
        count1=count2=0;
        for (auto x : nums)
            if (x == m1) ++count1;
            else if (x == m2) ++count2;
        
        vector<int> ans;
        if (count1 > nums.size()/3) ans.push_back(m1);
        if (count2 > nums.size()/3) ans.push_back(m2);
        return ans;
    }
};
