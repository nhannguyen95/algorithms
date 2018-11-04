// N = number of booking
// O(N) in space, O(NlogN) in time
bool comp(pair<int, int> e1, pair<int, int> e2) {
    return ((e1.first < e2.first) ||
            ((e1.first == e2.first) && (e1.second > e2.second)));
}

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    vector<pair<int, int>> events;
    for(int start : arrive) events.push_back(make_pair(start, 0));
    for(int end : depart) events.push_back(make_pair(end, 1));

    sort(events.begin(), events.end(), comp);

    int count = 0;
    int maxGuest = 0;
    for(auto event : events) {
        if (event.second == 0) {
            count++;
        } else {
            count--;
        }
        maxGuest = max(maxGuest, count);
    }

    return maxGuest <= K;
}
