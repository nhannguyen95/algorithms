// O(3N) in space
// O(2N) in time
int Solution::largestRectangleArea(vector<int> &A) {
    int n = (int) A.size();
    if (n == 0) return 0;

    deque<int> d;
    d.push_back(-1);
    vector<int> l(n), r(n);
    for(int i = 0; i < n; i++) {
        while(d.size() > 1 && A[d.back()] >= A[i]) {
            r[d.back()] = (A[d.back()] > A[i]) ? i - 1 : i;
            d.pop_back();
        }

        l[i] = d.back() + 1;
        d.push_back(i);
    }
    while(d.size() > 1) {
        r[d.back()] = n - 1;
        d.pop_back();
    }

    int maxArea = A[0];
    for(int i = 0; i < n; i++) {
        maxArea = max(maxArea, A[i] * (r[i] - l[i] + 1));
    }
    return maxArea;
}

// O(N) in space
// O(2N) in time
int Solution::largestRectangleArea(vector<int> &heights) {
    heights.push_back(0);  // Add the possible lowest height

    int n = (int) heights.size();

    int maxArea = heights[0];
    stack<int> s;
    for(int i = 0; i < n; i++) {
        while(!s.empty() && heights[s.top()] >= heights[i]) {  // > is possible
            int h = heights[s.top()];
            s.pop();

            int j = s.empty() ? -1 : s.top();
            maxArea = max(maxArea, h * (i - j - 1));
        }

        s.push(i);
    }

    return maxArea;
}
