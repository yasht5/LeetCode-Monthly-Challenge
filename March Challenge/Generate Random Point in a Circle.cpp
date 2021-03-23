class Solution {
public:
    double rad, x, y;
    Solution(double radius, double x_center, double y_center) {
        
        rad = radius;
        x = x_center;
        y = y_center;
    }
    
   
    vector<double> randPoint() {
        
        double r = sqrt((double)rand() / RAND_MAX);
        
        double ang = (double)rand() / RAND_MAX * 2 * M_PI;
        
        
        return vector<double>{x+r*rad*cos(ang), y+r*rad*sin(ang)};
    }
    
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
