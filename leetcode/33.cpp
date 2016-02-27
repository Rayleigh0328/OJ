class Solution {
private:
    int find_gap (vector<int>& a, int left, int right)
    {
        int mid = (left+right) >> 1;
        if (left == mid) return left;
        if (a[mid-1] > a[mid]) return mid;
        if (a[left] < a[mid]) return find_gap(a,mid,right);
        return find_gap(a,left,mid);
    }
    
    int solve(vector<int>&a, int left, int right, int target)
    {
        if (left >= right) return -1;
        int mid = (left+right) >> 1;
        //cout << left << " " << right << " " << mid << endl;
        if (a[mid] == target) return mid;
        if (a[mid]<target) return solve(a,mid+1,right,target);
        else return solve(a,left,mid,target);
    }
public:
    int search(vector<int>& a, int target) 
    {
        if (a.empty()) return -1;
        if (a.size()==1)
            if (a[0] == target) return 0;
            else return -1;
            
        const int n = a.size();
        // no rotation
        if (a[0]<a[n-1]) return solve(a,0,n,target);
        
        int pos = find_gap(a,0,n);
        //cout << "pos: " << pos << endl;
        int ans = solve(a,0,pos,target);
        if (ans != -1) return ans;
        return solve(a,pos,n,target);
    }
};