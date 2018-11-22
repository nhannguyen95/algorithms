// Solution 1
class Solution {
public:
    bool detectCapitalUse(string word) {
        for(int i = word.size()-1; i > 0; i--) {
            bool different = islower(word[i]) ^ islower(word[i-1]);
            if (different) {
                if (i == 1 && isupper(word[0]))
                    return true;
                return false;
            }
        }
        return true;
    }
};
