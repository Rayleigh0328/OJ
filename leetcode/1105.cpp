// dp: f[i] denotes the height after 
// finish first i book and i+1 starts with a new row
// boundary f[0] = 0;
// f[i] = min(f[j-1] + max{h[j]...h[i]}) where sum(w[j]..w[i]) <= shelf_width

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        vector<int> f(n+1,0);

        for (int i=1; i<=n; ++i){    
            int max_height=books[i-1][1];
            int total_width = books[i-1][0];
            f[i] = f[i-1] + max_height;
            
            for (int j=i-1;j>=1;--j){
                total_width += books[j-1][0];
                if (total_width > shelf_width) break;
                max_height = max(max_height, books[j-1][1]);
                f[i] = min(f[i], f[j-1] + max_height);
            }
            
        }
        return f[n];
    }
};
