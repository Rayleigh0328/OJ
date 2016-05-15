class Solution {
private:
    bool unique(vector<int>& cur_vect, vector<vector<int>>& ans)
    {
        for (int i=0;i<ans.size();++i)
        {
            if (ans[i].size() != cur_vect.size()) continue;
            bool pass = false;
            for (int j=0;j<ans[i].size();++j)
                if (ans[i][j] != cur_vect[j]) pass = true;
            if (!pass) return false;
        }
        return true;
    }
    
    int find(int tar, int left, int right,vector<int> &a)
    {
        while (left < right)
        {
            if (left + 1 == right)
                if (a[left] == tar) return left;
                else 
                    if (a[right] == tar) return right;
                    else return -1;
                
             int mid = (left + right)/2;
             if (a[mid] == tar) return mid;
             if (a[mid] < tar) left = mid + 1;
             else right = mid - 1;
        }
        if (left == right && a[left] == tar) return left;
        return -1;
    }
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) 
    {
        vector<vector<int>> ans;
        ans.clear();
        int len = a.size();
        sort(a.begin(), a.end());
       
        for (int i=0; i<len-3; ++i)
        {
            // cout << "here" << endl;
            // cout << "i: " << i << endl << "up: " << a.size() - 3<< endl;
            if (a[i] + 3*a[i+1] > target) break;
            else
            {
                for (int j=i+1;j<len-2;++j)
                    if (a[i] + a[j] + 2*a[j+1] > target) break;
                    else
                    {
                        for (int k = j+1; k<len-1;++k)
                        {
                            int rest = target - a[i] - a[j] - a[k];
                            if (rest < a[k+1]) break;
                            else
                            {
                                int last_pos = find(rest, k+1, len-1,a);
                                //cout << a[i] << " " << a[j] << " " << a[k] << " " << rest << endl;
                                if (last_pos != -1)
                                {
                                    vector<int> cur_vect = {a[i],a[j],a[k],a[last_pos]};
                                    if (unique(cur_vect, ans))
                                        ans.push_back(cur_vect);
                                }
                            }
                        }
                    }
            }
        }
        return ans;
    }
};