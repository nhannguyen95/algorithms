int Solution::colorful(int A) {
    string s = to_string(A);
    unordered_set<int> products;
    for(int i = 0; i < (int)s.size() - 1; i++) {
        for(int j = i + 1; j < (int)s.size(); j++) {
            int product = 1;
            for(int k = i; k <= j; k++) {
                product *= (s[k] - '0');
            }

            if (products.find(product) != products.end()) {
                return 0;
            }
            products.insert(product);
        }
    }
    return 1;
}
