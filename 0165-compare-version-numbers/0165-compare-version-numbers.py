class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1 = [int(x) for x in version1.split(".")]
        v2 = [int(x) for x in version2.split(".")]

        m = len(v1)
        n = len(v2)

        if m < n:
            for _ in range(n - m):
                v1.append(0)
        elif n < m:
            for _ in range(m - n):
                v2.append(0)

        for i in range(len(v1)):
            if v1[i] > v2[i]:
                return 1
            elif v1[i] < v2[i]:
                return -1

        return 0