// https://leetcode.com/problems/largest-triangle-area/

// Solution 1: O(N^3) in time, O(1) in space
class Solution {
public:
    
    /* Return vector ab */
    vector<int> getVector2D(vector<int> a, vector<int> b) {
        return vector<int>({b[0] - a[0], b[1] - a[1]});    
    }
    
    /* Return a scalar that is cross product between 2 vector (in z) */
    double cross(vector<int> a, vector<int> b) {
        return a[0]*b[1] - b[0]*a[1];
    }
    
    double computeTriangleArea(vector<int> a, vector<int> b, vector<int> c) {
        vector<int> ab = getVector2D(a, b);
        vector<int> ac = getVector2D(a, c);
        
        double cp = cross(ab, ac);
        
        double area = abs(cp) / 2.0;
        return area;
    }
    
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double maxArea = 0;
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                for(int k = j+1; k < n; k++) {
                    double area = computeTriangleArea(points[i], points[j], points[k]);
                    maxArea = max(maxArea, area);
                }
        return maxArea;
    }
};
