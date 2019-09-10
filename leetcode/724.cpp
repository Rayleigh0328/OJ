class Solution {
public:
    int pivotIndex(vector<int>& a) {
    	int sum = 0;
    	for (int x : a) sum += x;
    	int left_sum = 0;
    	for (int i=0;i<a.size();left_sum+=a[i++])
    		if (left_sum == sum - left_sum - a[i]) return i;
    	return -1;
    }
};
