int Solution::strStr(const string &haystack, const string &needle) {

    for(int i = 0; i < (int)haystack.size() - (int)needle.size() + 1; i++) {

        int j = 0;
        while(j < (int)needle.size() && haystack[i + j] == needle[j]) {
            j++;
        }

        if (j == (int)needle.size()) {
            return i;
        }
    }

    return -1;
}
