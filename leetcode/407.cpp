// #define TEST

enum Color{WHITE, GREY, BLACK};

typedef pair<int, int> Cell;

class Solution {    
    vector<int> x_diff{0,0,-1,1};
    vector<int> y_diff{-1,1,0,0};
    
    vector<vector<int>> grid;
    int n,m;
    vector<vector<Color>> color;
    vector<Cell> a;
    int ans;
    int white_count;
    
    bool in_board(const Cell &x){
        return in_board(x.first, x.second);
    }
    
    bool in_board(int x, int y){
        return (0<=x && x < n && 0<=y && y<m);
    }
    
    bool on_boundary(const Cell &x){
        return on_boundary(x.first, x.second);
    }
    
    bool connect_to_grey(const Cell &p){
        int x = p.first;
        int y = p.second;
        int next_x, next_y;
        for (int d = 0; d < 4; ++d){
            next_x = x + x_diff[d];
            next_y = y + y_diff[d];
            if (in_board(next_x, next_y) && color[next_x][next_y] == GREY) return true;
        }
        return false;
    }
    
    bool on_boundary(int x, int y){
        return (in_board(x,y) && (x == 0 || x == n-1 || y == 0 || y == m-1));
    }
    
    int get_height(const Cell &x){
        return grid[x.first][x.second];
    }
    
    Color get_color(const Cell &x){
        return color[x.first][x.second];
    }
    
    void set_color(const Cell &x, Color c){
        color[x.first][x.second] = c;
    }
    
    void color_layer(int left, int right){
        queue<Cell> que;
        for (int i=left;i<right;++i){
            if (on_boundary(a[i]) || connect_to_grey(a[i])) {
                que.push(a[i]);
                set_color(a[i], GREY);
            }
            else {
                set_color(a[i], WHITE);
                ++white_count;
            }
        }

        int x, y, next_x, next_y;
        while (!que.empty()){
            x = que.front().first;
            y = que.front().second;
            que.pop();
            
            for (int i=0;i<4;++i){
                next_x = x + x_diff[i];
                next_y = y + y_diff[i];
                if (in_board(next_x, next_y) && color[next_x][next_y] == WHITE){
                    color[next_x][next_y] = GREY;
                    --white_count;
                    que.push(Cell(next_x, next_y));
                }
            }
        }
        
    }
    
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        grid = heightMap;
        if (grid.empty() || grid[0].empty()) return 0;
        n = grid.size();
        m = grid[0].size();
        
        color = vector<vector<Color>>(n, vector<Color>(m, BLACK));
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                a.push_back(Cell(i,j));
        sort(a.begin(), a.end(), [&heightMap](const Cell &x, const Cell &y){return heightMap[x.first][x.second] < heightMap[y.first][y.second];});

        ans = 0, white_count = 0;
        int left = 0, right, prev_h, next_h;
        while (left < a.size()){
            right = left;
            prev_h = get_height(a[left]);
            while (right < a.size() && get_height(a[right]) == prev_h) ++right;
            if (right >= a.size()) break;
            next_h = get_height(a[right]);
            
            color_layer(left, right);
            
            ans += white_count * (next_h - prev_h);
            left = right;
        }
        
        return ans;
    }
};
