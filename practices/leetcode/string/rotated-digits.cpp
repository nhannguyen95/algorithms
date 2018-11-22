// Solution 1
class Solution {
public:
    pair<string, bool> rotate(string num) {
        map<char, char> rot{
            {'0', '0'}, {'1', '1'}, {'8','8'},
            {'2', '5'}, {'5', '2'}, {'6','9'},
            {'9', '6'}
        };
        for(char & c : num) {
            if (rot.find(c) != rot.end())
                c = rot[c];
            else return make_pair("", false);
        }
        return make_pair(num, true);
    }
    
    bool isGood(int x) {
        string num = to_string(x);
        pair<string, bool> rot = rotate(num);
        return rot.second && num.compare(rot.first);    
    }
    
    int rotatedDigits(int N) {
        int ans = 0;
        for(int i = 1; i <= N; i++)
            ans += isGood(i);
        return ans;
    }
};

// Solution 2
class Solution {
public:
    bool isGood(int x) {
        bool diff = false;
        while(x) {
            int d = x % 10;
            x /= 10;
            
            if (d == 3 || d == 4 || d == 7)
                return false;
            if (d == 2 || d == 5 || d == 6 || d == 9)
                diff = true;
            
        }
        return diff;
    }
    
    int rotatedDigits(int N) {
        int ans = 0;
        for(int i = 1; i <= N; i++)
            ans += isGood(i);
        return ans;
    }
};
