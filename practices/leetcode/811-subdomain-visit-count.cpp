// https://leetcode.com/problems/subdomain-visit-count/

// Solution 1
class Solution {
public:
    vector<string> split(string s, string delim = " ") {
        vector<string> tokens;
        size_t i = 0;
        for(size_t p = 0; (p = s.find(delim, i)) != s.npos;) {
            string token = s.substr(i, p - i);
            tokens.push_back(token);
            i = p + delim.size();
        }
        if (i < s.size()) tokens.push_back(s.substr(i));
        return tokens;
    }
    
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        
        unordered_map<string, int> cntDomains;
        
        for(string & cpdomain : cpdomains) {
            auto cp_domain = split(cpdomain, " ");
            
            int cp = stoi(cp_domain[0]);
            string domain = cp_domain[1];
            for(int i = domain.size() - 1; i >= -1; i--)
                if (i == -1 || domain[i] == '.') {
                    string subdomain = domain.substr(i + 1);
                    cntDomains[subdomain] += cp;
                }
        }
        
        vector<string> ans;
        for(auto it = cntDomains.begin(); it != cntDomains.end(); it++) {
            ans.push_back(to_string(it->second) + " " + it->first);
        }
        return ans;
    }
};
