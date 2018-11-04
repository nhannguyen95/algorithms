void Solution::reverseWords(string &A) {
    string reversedA;
    stack<char> S;
    for(int i = (int)A.size() - 1; i >= 0; i--) {
        if (A[i] != ' ') S.push(A[i]);
        else {
            while(!S.empty()) {
                char c = S.top();
                S.pop();
                reversedA.push_back(c);
            }

            if (reversedA.back() != ' ') {
                reversedA.push_back(' ');
            }
        }
    }

    while(!S.empty()) {
        char c = S.top();
        S.pop();
        reversedA.push_back(c);
    }

    if (reversedA.back() == ' ') {
        reversedA.pop_back();
    }

    A = reversedA;
}
