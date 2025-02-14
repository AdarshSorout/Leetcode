

class Solution:

    def __init__(self):
        self.n = 0
        self.result = []

    def isValid(self, s: str) -> bool:
        if s[0] == '0' :
            return False
        val = int(s)
        return val <= 255

    def solve(self, s: str, idx: int, part: int, curr: str):
        if idx == self.n and part == 4:
            self.result.append(curr[:-1])
            return 

        if idx + 1 <= self.n:
            self.solve(s, idx + 1, part + 1, curr + s[idx:idx+1] + ".")

        if idx + 2 <= self.n and self.isValid(s[idx:idx+2]):
            self.solve(s, idx + 2, part + 1, curr + s[idx:idx+2] + ".")

        if idx + 3 <= self.n and self.isValid(s[idx:idx+3]):
            self.solve(s, idx + 3, part + 1, curr + s[idx:idx+3] + ".")

    def restoreIpAddresses(self, s: str) -> List[str]:
        self.n = len(s)
        self.result.clear()

        if self.n > 12:
            return []

        self.solve(s, 0, 0, "")
        return self.result









