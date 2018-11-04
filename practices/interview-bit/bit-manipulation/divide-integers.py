class Solution:
    def divide(self, dividend, divisor):
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31

        sign = -1 if (dividend < 0) ^ (divisor < 0) else 1

        dividend = abs(dividend)
        divisor = abs(divisor)

        # answer
        q = 0

        for i in range(31, -1, -1):
            if dividend >= (divisor << i):
                dividend -= (divisor << i)
                q |= (1 << i)

        if sign < 0:
            q = -q

        return INT_MAX if (q >= INT_MAX or q < INT_MIN) else q
