// Input : X and Y co-ordinates of the points in order.
// Each point is represented by (X[i], Y[i])
int computeStep(int xPrev, int yPrev, int xCur, int yCur) {
    int deltaX = abs(xCur - xPrev);
    int deltaY = abs(yCur - yPrev);
    return max(deltaX, deltaY);
}

int Solution::coverPoints(vector<int> &X, vector<int> &Y) {
    assert(X.size() == Y.size())

    // Base case
    if (X.size() <= 1) {
        return 0;
    }

    int steps = 0;
    for(int i = 1; i < n; i++) {
        steps += computeStep(X[i], Y[i], X[i - 1], Y[i - 1]);
    }
    return steps;
}
