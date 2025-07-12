class Solution:
    def earliestAndLatest(self, n, firstPlayer, secondPlayer):
        memo = {}

        def dfs(mask, a, b, round):
            if (mask, a, b, round) in memo:
                return memo[(mask, a, b, round)]

            if not (mask & (1 << a)) or not (mask & (1 << b)):
                return float('inf'), -float('inf')

            alive = [i for i in range(n) if (mask >> i) & 1]
            m = len(alive)

            for i in range(m // 2):
                x, y = alive[i], alive[m - 1 - i]
                if {x, y} == {a, b}:
                    return round, round

            res = [float('inf'), -float('inf')]

            def backtrack(idx, new_mask):
                if idx >= m // 2:
                    if m % 2 == 1:
                        mid = alive[m // 2]
                        new_mask |= (1 << mid)
                    sub = dfs(new_mask, a, b, round + 1)
                    res[0] = min(res[0], sub[0])
                    res[1] = max(res[1], sub[1])
                    return

                x, y = alive[idx], alive[m - 1 - idx]
                backtrack(idx + 1, new_mask | (1 << x))  # x wins
                backtrack(idx + 1, new_mask | (1 << y))  # y wins

            backtrack(0, 0)
            memo[(mask, a, b, round)] = (res[0], res[1])
            return res[0], res[1]

        mask = (1 << n) - 1
        res = dfs(mask, firstPlayer - 1, secondPlayer - 1, 1)
        return [res[0], res[1]]
