// Solution 1: DSU
class DisjointSet {
private:
    int n, nComponents;
    vector<int> lab, idx;
    
    int getId(int v) {
        return idx[v];    
    }
    
public:
    DisjointSet(const vector<int> & _A) {
        n = _A.size();
        nComponents = _A.size();
        lab.assign(n, -1);
        
        // Map from value to index.
        int m = *max_element(_A.begin(), _A.end());
        idx.assign(m+1, -1);
        for(int i = 0; i < n; i++)
            idx[_A[i]] = i;
    }
    
    int findRoot(int u) {
        return lab[u] < 0 ? u : lab[u] = findRoot(lab[u]);
    }
    
    void merge(int u, int v) {
        u = getId(u);
        v = getId(v);
        if (u == -1 || v == -1) return;
        
        u = findRoot(u);
        v = findRoot(v);
        if (u == v) return;
        
        if (lab[u] > lab[v]) swap(u, v);
        lab[u] += lab[v];
        lab[v] = u;
        nComponents--;
    }
    
    int getNumberOfComponents() {
        return nComponents;
    }
};

class Solution {
public:
    int getLength(ListNode* head) {
        int len = 0;
        while(head != NULL) {
            len++;
            head = head->next;
        }
        return len;
    }
    
    int numComponents(ListNode* head, vector<int>& G) {
        // Get length of the linked-list.
        int n = getLength(head);
        
        // Mark elements that appear in G
        vector<bool> inG(n, false);
        for(int e : G) inG[e] = true;
        
        // Use disjoint-set data structure to connect
        // consecutive elements in the linked list that
        // appear in G
        DisjointSet ds(G);
        ListNode* node = head;
        while(node && node->next) {
            int u = node->val;
            int v = node->next->val;
            if (inG[u] && inG[v]) ds.merge(u, v);
            node = node->next;
        }
        
        return ds.getNumberOfComponents();
    }
};

// Solution 2
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        int m = *max_element(G.begin(), G.end());
        vector<bool> inG(10000, false);
        for(int val : G) inG[val] = true;
        
        int ans = 0;
        ListNode* node = head;
        while(node) {
            if (inG[node->val] && (node->next == NULL || !inG[node->next->val]))
                ans++;
            node = node->next;
        }
        return ans;
    }
};
