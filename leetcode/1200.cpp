class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int min_diff = arr[1] - arr[0];
        for (int i=1;i<arr.size();++i)
            if (arr[i] - arr[i-1] < min_diff) 
                min_diff = arr[i] - arr[i-1];
        vector<vector<int>> ans;
        for (int i=1;i<arr.size();++i)
            if (arr[i] - arr[i-1] == min_diff){
                vector<int> tmp = {arr[i-1], arr[i]};
                ans.push_back(tmp);
            }
        return ans;
    }
};
