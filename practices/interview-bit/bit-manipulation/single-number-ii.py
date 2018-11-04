class Solution:
    # @param A : tuple of integers
    # @return an integer
    def singleNumber(self, A):
        ones = 0
        twos = 0
        threes = 0
        for x in A:
            twos |= ones & x
            ones ^= x
            threes = ones & twos
            ones &= ~threes
            twos &= ~threes
        return ones
