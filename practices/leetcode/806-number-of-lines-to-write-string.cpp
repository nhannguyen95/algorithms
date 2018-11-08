// Solution 1
// N = len(S)
// O(N) in time
// O(1) in space
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int nLines = 1;  // S is not empty.
        int nChars = 0;
        for(char & c : S) {
            nChars += widths[c - 'a'];
            if (nChars > 100) {
                nLines++;
                nChars = widths[c - 'a'];
            }
        }
        return vector<int>({nLines, nChars});
    }
};
