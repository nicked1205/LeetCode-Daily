class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        from collections import defaultdict

        freq = defaultdict(int)
        res = []

        for i in range(k):
            freq[nums[i]] += 1

        def compute_xsum():
            items = sorted(freq.items(), key=lambda p: (-p[1], -p[0]))
            return sum(val * cnt for val, cnt in items[:x])

        res.append(compute_xsum())

        i = 0
        j = k

        while j < len(nums):
            freq[nums[i]] -= 1
            if freq[nums[i]] == 0:
                del freq[nums[i]]

            freq[nums[j]] += 1

            res.append(compute_xsum())

            i += 1
            j += 1

        return res