class Solution {
    const double pi = 3.1415926535;
    double x0, y0, r;
    
    double rand01_open(){
        return rand() / (RAND_MAX + 1.0);
    }
    
    double rand01_close(){
        return static_cast<double>(rand()) / (RAND_MAX);
    }
    
public:
    
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x0 = x_center;
        y0 = y_center;
    }
    
    vector<double> randPoint() {
        double theta = rand01_open() * 2 * pi;
        double rou = sqrt(rand01_close()) * r;
        return {sin(theta) * rou + x0, cos(theta) * rou + y0};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
