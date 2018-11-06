// Solution 1: long
class Solution {
public:
    pair<string, string> splitEmail(string email) {
        int atPos = email.find('@');
        pair<string, string> p;
        p.first = email.substr(0, atPos);
        p.second = email.substr(atPos + 1);
        return p;
    }
    
    string ignoreAfterPlus(string name) {
        int plusPos = name.find('+');
        return name.substr(0, plusPos);
    }
    
    string removeDots(string str) {
        string noDotStr = "";
        for(char & c : str)
            if (c != '.') noDotStr.push_back(c);
        return noDotStr;
    } 
    
    string normalizeLocalName(string name) {
        name = ignoreAfterPlus(name);
        name = removeDots(name);
        return name;
    }
    
    int numUniqueEmails(vector<string>& emails) {
        set<string> seperatedLocalNames;
        for(string & email : emails) {
            auto p = splitEmail(email);
            string localName = normalizeLocalName(p.first);
            string domainName = p.second;
            seperatedLocalNames.insert(localName + "@" + domainName);
        }
        return seperatedLocalNames.size();
    }
};

// Solution 2: shorter, faster
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> uniqueEmails;
        for(auto & email : emails) {
            string newEmail = "";
            
            bool metAt = false;
            bool ignoring = false;
            for(char & c : email) {
                if (c == '+' && !metAt) {
                    ignoring = true;
                    continue;
                } 
                if (c == '@') {
                    metAt = true;
                    ignoring = false;
                }
                
                if ((c != '.' && !ignoring) || (c == '.' && metAt))
                    newEmail.push_back(c);
            }
            uniqueEmails.insert(newEmail);
        }
        return uniqueEmails.size();
    }
};
