// https://leetcode.com/problems/mirror-reflection/

class Solution {
public:
    double EPS = 1e-6;
    
    bool close(double x, double y) {
        return abs(x - y) < EPS;
    }
        
    int mirrorReflection(int p, int q) {
        double x = 0, y = 0;
        double ux = p, uy = q;
        
        while (!((close(x, p) && (close(y, 0) || close(y, p))) ||
              (close(x, 0) && close(y, p)))) {
            double t = 1e9;
            if ((-x/ux) > EPS) t = min(t, -x / ux);
            if ((-y/uy) > EPS) t = min(t, -y / uy);
            if (((p-x)/ux) > EPS) t = min(t, (p-x) / ux);
            if (((p-y)/uy) > EPS) t = min(t, (p-y) / uy);
            
            x += t * ux;
            y += t * uy;
            
            if (close(x, 0) || close(x, p)) ux *= -1;
            if (close(y, 0) || close(y, p)) uy *= -1;
        }
        
        if (close(x, 0) && close(y, p)) return 2;
        return close(y, 0) ? 0 : 1;
    }
};
