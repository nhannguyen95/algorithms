# Solution 1: binary search, TLE (passed 46/48 test cases)
# O(N_A*N_B+N_C*N_D) in space
# ...
class Solution(object):
    def fourSumCount(self, A, B, C, D):
        # Base case
        if len(A) == 0 or len(B) == 0 or len(C) == 0 or len(D) == 0:
            return 0
        
        AB = []
        for i in range(len(A)):
            for j in range(len(B)):
                AB.append(A[i] + B[j])
        
        CD = []
        for i in range(len(C)):
            for j in range(len(D)):
                CD.append(C[i] + D[j])
                
        def find_left_most(a, x):
            low = 0
            high = len(a)
            while low < high:
                mid = (low + high) // 2
                if a[mid] < x: low = mid + 1
                else: high = mid
            
            return low if low < len(a) and a[low] == x else -1
        
        def find_right_most(a, x):
            low = -1
            high = len(a) - 1
            while low < high:
                mid = (low + high + 1) // 2
                if a[mid] > x: high = mid - 1
                else: low = mid
            return high if high >= 0 and a[high] == x else -1
                
        CD.sort()
        res = 0
        for i in range(len(AB)):
            lid = find_left_most(CD, -AB[i])
            rid = find_right_most(CD, -AB[i])
            if lid != -1: res += (rid - lid + 1)
        return res

# Solution 2: hash table
# O(N_A + N_B) in space
# O(N_A*N_B + N_C*N_D) in time
class Solution(object):
    def fourSumCount(self, A, B, C, D):
        sumAB = collections.defaultdict(int)
        for i in range(len(A)):
            for j in range(len(B)):
                sumAB[A[i]+B[j]] += 1
        
        res = 0
        for i in range(len(C)):
            for j in range(len(D)):
                res += sumAB[-C[i] - D[j]]
        return res
