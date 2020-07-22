struct Point { 
    double x, y; 
}; 


class Solution {
    
    vector<Point> test_point = { { -1.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 }, { 0.0, -1.0 } }; 
    double lower_limit = 1e-4;
    
    double distSum(Point p, vector<Point> &arr) { 
        const int n = arr.size();
        double sum = 0; 
        for (int i = 0; i < n; i++) { 
            double distx = abs(arr[i].x - p.x); 
            double disty = abs(arr[i].y - p.y); 
            sum += sqrt((distx * distx) + (disty * disty)); 
        } 
        return sum; 
    } 
    
    double geometricMedian(vector<Point> &arr) { 
  
        const int n = arr.size();
        // Current x coordinate and y coordinate 
        Point current_point; 

        for (int i = 0; i < n; i++) { 
            current_point.x += arr[i].x; 
            current_point.y += arr[i].y; 
        } 

        // Here current_point becomes the 
        // Geographic MidPoint 
        // Or Center of Gravity of equal 
        // discrete mass distributions 
        current_point.x /= n; 
        current_point.y /= n; 

        // minimum_distance becomes sum of 
        // all distances from MidPoint to 
        // all given points 
        double minimum_distance = distSum(current_point, arr); 

        int k = 0; 
        while (k < n) { 
            for (int i = 0; i < n && i != k; i++) { 
                Point newpoint; 
                newpoint.x = arr[i].x; 
                newpoint.y = arr[i].y; 
                double newd =  distSum(newpoint, arr); 
                if (newd < minimum_distance) { 
                    minimum_distance = newd; 
                    current_point.x = newpoint.x; 
                    current_point.y = newpoint.y; 
                } 
            } 
            k++; 
    } 
  
    // Assume test_distance to be 1000 
    double test_distance = 1000; 
    int flag = 0; 
  
    // Test loop for approximation starts here 
    while (test_distance > lower_limit) { 
  
        flag = 0; 
  
        // Loop for iterating over all 4 neighbours 
        for (int i = 0; i < 4; i++) { 
  
            // Finding Neighbours done 
            Point newpoint; 
            newpoint.x = current_point.x + (double)test_distance * test_point[i].x; 
            newpoint.y = current_point.y + (double)test_distance * test_point[i].y; 
  
            // New sum of Euclidean distances 
            // from the neighbor to the given 
            // data points 
            double newd = distSum(newpoint, arr); 
  
            if (newd < minimum_distance) { 
  
                // Approximating and changing 
                // current_point 
                minimum_distance = newd; 
                current_point.x = newpoint.x; 
                current_point.y = newpoint.y; 
                flag = 1; 
                break; 
            } 
        } 
  
        // This means none of the 4 neighbours 
        // has the new minimum distance, hence 
        // we divide by 2 and reiterate while 
        // loop for better approximation 
        if (flag == 0) 
            test_distance /= 2; 
    } 
  
    cout << "Geometric Median = ("
         << current_point.x << ", "
         << current_point.y << ")"; 
    cout << " with minimum distance = "
         << minimum_distance; 
    return minimum_distance;
} 
    
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        vector<Point> a;
        for (auto &e : positions){
            Point p;
            p.x = e[0];
            p.y = e[1];
            a.push_back(p);
        }
        return geometricMedian(a);
    }
};
