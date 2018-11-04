# Solution 1: sorting + binary search + 2 pointers
# N = len(houses), M = len(heaters)
# O(NlogN + MlogM + O((M+max(M, N))log1e9) in time
# O(M) in space
class Solution:
    def findRadius(self, houses, heaters):
        # Base case
        if len(houses) == 0 or len(heaters) == 0:
            return 0
        
        houses.sort()
        heaters.sort()
        
        def in_range(val, pos):
            if pos < val[0]: return -1
            elif pos > val[1]: return 1
            return 0
            
        def check_radius(r):
            vals = [(pos-r, pos+r) for pos in heaters]
            # 2 pointers
            i = 0
            j = 0
            while(i < len(vals) and j < len(houses)):
                t = in_range(vals[i], houses[j])
                if t == 0: j += 1
                elif t < 0: return False
                else: i += 1
            return j >= len(houses)
            
        low = 0
        high = 1000000001
        while low < high:
            mid = (low + high) // 2
            if not check_radius(mid): low = mid + 1
            else: high = mid
        return low
  
# Solution 2: sorting + binary search
# For each house, find distance to left heaters and right heaters
# res = max(res, min(dist left, dist right)
class Solution:
    def findRadius(self, houses, heaters):
        heaters.sort()
        
        def upper_bound(x):
            low, high = 0, len(heaters)
            while low < high:
                mid = (low + high) // 2
                if heaters[mid] < x: low = mid + 1
                else: high = mid
            return low
        
        res = 0
        for pos in houses:
            i = upper_bound(pos)
            dist_l = float('inf') if i == 0 else pos - heaters[i-1]
            dist_r = float('inf') if i == len(heaters) else heaters[i] - pos
            res = max(res, min(dist_l, dist_r))
        return res      
