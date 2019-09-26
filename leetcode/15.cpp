class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
       
        sort(nums.begin(), nums.end());
    
        vector<int> a;
        a.clear();
        
        map<int, int> count;
        count.clear();
        
        for (int i=0;i<nums.size();++i)
            if (count.find(nums[i]) == count.end())
            {
                count.emplace(nums[i], 1);
                a.push_back(nums[i]);
            }
            else
                ++count[nums[i]];
        //for (int i=0;i<a.size();++i)
          //  cout << a[i] << " " << count[a[i]] << endl;
            
        vector<vector<int>> result;
        result.clear();
        
        for (int i=0;i<a.size();++i)
        {
            if (a[i] == 0 && count[0] >= 3) 
            {
                result.push_back(vector<int>(3,0));
                continue;
            }
            
            if (count[a[i]] >=2 && a[i] < 0 && count.find(-2*a[i])!=count.end()) 
            {
                result.push_back(vector<int>(2,a[i]));
                result[result.size()-1].push_back(-2*a[i]);
            }
                
            for (int j=i+1;j<a.size();++j)
            {
                //cout << "cand " << a[i] << " " << a[j] << endl; 
                if ( -(a[i]+a[j]) == a[j] && count[a[j]]>=2)
                {
                    result.push_back(vector<int>());
                    result[result.size()-1].push_back(a[i]);
                    result[result.size()-1].push_back(a[j]);                        
                    result[result.size()-1].push_back(a[j]);
                }
                else 
                    if (-(a[i]+a[j]) > a[j] && count.find(-(a[i]+a[j]))!=count.end())
                    {
                        //cout << "ans" << a[i] << " " << a[j] << endl;
                        result.push_back(vector<int>());
                        result[result.size()-1].push_back(a[i]);        
                        result[result.size()-1].push_back(a[j]);
                        result[result.size()-1].push_back(-(a[i]+a[j]));
                    }
            }
        }
        return result;
    }
};
