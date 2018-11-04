long long gcd(long long a, long long b) {
    return (a == 0) ? b : gcd(b % a, a);
}

string Solution::fractionToDecimal(int a, int b) {
    assert(b != 0);

    // Base case
    if (a == 0) return "0";

    long long _a = a;
    long long _b = b;

    // For simplicity, we work with a > 0 and b > 0,
    // save the sign
    string sign = ((_a^_b) >= 0) ? "" : "-";  // Only work for integers
    // cout << "sign: " << sign << '\n';
    _a = abs(_a);
    _b = abs(_b);

    // Reducing the fraction
    long long g = gcd(_a, _b);
    _a /= g;
    _b /= g;

    // We only work with a / b where a < b
    string quotient = to_string((_a / _b));
    _a = _a % _b;

    // Division algorithm a / b where a < b
    string decimal = "";
    unordered_map<long long, int> pos;
    while(_a > 0) {
        _a *= 10;

        // Re encountering the numerator '_a' means
        // having repetition
        if (pos.find(_a) != pos.end()) {
            decimal.insert(decimal.begin() + pos[_a], '(');
            decimal.push_back(')');
            break;
        }

        long long digit = _a / _b;
        decimal.push_back('0' + digit);
        pos[_a] = (int)decimal.size() - 1;
        _a = _a % _b;
    }

    if (decimal != "") decimal = "." + decimal;
    return sign + quotient + decimal;
}
