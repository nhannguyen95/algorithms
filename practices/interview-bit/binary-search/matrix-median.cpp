int Solution::findMedian(vector<vector<int> > &A) {
    int l = 0, r = INT_MAX;
    int mid, req = (int)A.size() * (int)A[0].size();
    assert(req % 2);
    while(l < r){
        mid = l + (r - l) / 2;
        int cnt = 0;
        for(auto &i: A){
            //using upper bound in a sorted array to count number
            // of elements smaller than or equal to mid
            int p = upper_bound(i.begin(), i.end(), mid) - i.begin();
            cnt += p;
        }
        if(cnt >= (req/2 +1)) {
            r = mid;
        }
        else l = mid + 1;
    }
    return r;
}
