class Solution {
    
    int solve_min(int x, int y, int z){
        if (z == x + 2) return 0;
        if (y - x <= 2) return 1;
        if (z - y <= 2) return 1;
        return 2;
    }
    
public:
    vector<int> numMovesStones(int x, int y, int z) {
        vector<int> a{x,y,z};
        sort(a.begin(), a.end());
        return {solve_min(a[0],a[1],a[2]), a[2]-a[0]-2};
    }
};
