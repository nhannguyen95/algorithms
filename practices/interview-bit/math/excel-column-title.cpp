string Solution::convertToTitle(int A) {
    if (A <= 0) return "";
    string title;
    while(A > 0) {
        A--;
        title.push_back('A' + (A % 26));
        A /= 26;
    }
    reverse(title.begin(), title.end());
    return title;
}
