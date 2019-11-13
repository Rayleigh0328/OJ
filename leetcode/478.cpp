class Solution {
    
    double rand01(){
        // return a random double in [0,1]
        return static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
    }
    
    double rand11(){
        if (rand()%2 == 0) return rand01();
        else return -rand01();
    }
    
public:
    double r, x0, y0;
    
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x0 = x_center;
        y0 = y_center;
    }
    
    vector<double> randPoint() {
        double x = 1, y = 1;
        while (x*x + y*y > 1.0){
            x = rand11();
            y = rand11();
        }
        
        x *= r; y *= r;
        return {x + x0, y+y0};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
