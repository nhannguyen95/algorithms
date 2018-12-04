// Solution 1:
class Solution {
public:
    pair<int, int> addBit(int a, int b) {
        pair<int, int> res[2][2] = {
            { make_pair(0, 0), make_pair(0, 1) },
            { make_pair(0, 1), make_pair(1, 0) }
        };
        return res[a][b];
    }
    
    int getSum(int a, int b) {
        int sum = 0;
        int carry = 0;
        for(int i = 0; i < 32; i++) {
            int bitA = (a & (1 << i)) != 0;
            int bitB = (b & (1 << i)) != 0;
            
            auto t1 = addBit(bitA, bitB);
            auto t2 = addBit(t1.second, carry);
            carry = t1.first || t2.first;
            
            
            sum |= (t2.second << i);
        }
        return sum;
    }
};

// Solution 2:
class Solution {
public:
    int getSum(int a, int b) {
        if (a == 0) return b;
        if (b == 0) return a;
        
        int sum = 0;
        while(b != 0) {
            sum = a ^ b;       // a + b without the carry
            b = (a & b) << 1;  // compute the carry
            a = sum;
        }
        
        return sum;
    }
};
