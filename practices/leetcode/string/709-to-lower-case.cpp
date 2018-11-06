// Solution 1
class Solution {
public:
    string toLowerCase(string str) {
        string lower = "";
        for(char & c : str) {
            lower.push_back(tolower(c));
            // if (isupper(c)) lower.push_back(c + 'a' - 'A');
            // else lower.push_back(c);
        }
        return lower;
    }
};
