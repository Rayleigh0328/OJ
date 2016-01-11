class Solution {
private:
    struct point
    {
        int x;
        int y;
        
        point(int a, int b)
        {
            x = a;
            y = b;
        }
        
        bool operator<(const point& other) const
        {
            return y < other.y;
        }
    };
public:
    int maxArea(vector<int>& height) 
    {
        vector<point> a;
        for (int i=0;i<height.size();++i)
            a.push_back(point(i,height[i]));
        set<int> rem;
        for (int i=0;i<height.size();++i)
            rem.insert(i);
        sort(a.begin(), a.end());
        
        int result = 0;
        for (int i=0;i<a.size();++i)
        {
            int left = *rem.begin();
            int right = *rem.rbegin();
            result = max(result, a[i].y * (a[i].x - left));
            result = max(result, a[i].y * (right - a[i].x));
            
            set<int>::const_iterator tmp = rem.find(a[i].x);
            rem.erase(tmp);
        }
        return result;
    }
};