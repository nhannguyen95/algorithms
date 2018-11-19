// Solution 1: hash table with file content as key
class Solution {
public:
    struct FileInfo {
        string name;
        string content;
        FileInfo(string name, string content) :
            name(name), content(content) {}
    };
    
    vector<string> split(const string & s, const string delim = " ") {
        vector<string> tokens;
        size_t i = 0;
        for(size_t p = 0; (p = s.find(delim, i)) != s.npos; ) {
            string token = s.substr(i, p - i);
            if (token.compare("")) tokens.push_back(token);
            i = p + delim.size();
        }
        if (i < s.size()) tokens.push_back(s.substr(i));
        return tokens;
    }
    
    FileInfo getFileInfo(const string & file) {
        int p1 = file.find("(");
        int p2 = file.find(")");
        return FileInfo(file.substr(0, p1), file.substr(p1+1, p2-p1-1));
        // regex r("([^\\(]+)\\(([^\\)]*)\\)");
        // smatch sm;
        // regex_match (file, sm, r);
        // return FileInfo(sm[1], sm[2]);
    }
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> contentToDes;
        for(string & path : paths) {
            vector<string> list = split(path, " ");
            string& dirPath = list[0];
            for(int i = 1; i < list.size(); i++) {
                FileInfo fileInfo = getFileInfo(list[i]);
                contentToDes[fileInfo.content].push_back(dirPath + "/" + fileInfo.name);
            }
        }
        
        vector<vector<string>> ans;
        for(unsigned i = 0; i < contentToDes.bucket_count(); i++)
            for(auto it = contentToDes.begin(i); it != contentToDes.end(i); it++) {
                if (it->second.size() >= 2) {  // We have duplicated content!
                    ans.push_back(it->second);
                }
            }
        return ans;
    }
};
