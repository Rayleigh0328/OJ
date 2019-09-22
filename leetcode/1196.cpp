class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int count = 0;
        int sum = 0;
        for (int i=0;i<arr.size();++i)
            if (sum + arr[i] <= 5000) {
                ++count;
                sum += arr[i];
            }
            else break;
        return count;
    }
};
