import math

class Solution:
    def kthCharacter(self, k, operations):
        # Compute the smallest n such that 2^n >= k using math.log with base 2.
        n = int(math.ceil(math.log(k, 2)))
        shift = 0

        # Traverse backwards from n-1 down to 0.
        for i in range(n - 1, -1, -1):
            half = 1 << i  # This is 2^i.
            if k > half:
                k -= half
                shift += operations[i]
                
        # Return the character after applying shift modulo 26.
        return chr((shift % 26) + ord('a'))

# Example usage:
if __name__ == '__main__':
    sol = Solution()
    # Example: operations = [1, 0, 1, 0, 1] and k = 5; adjust as needed for testing.
    operations = [1, 0, 1, 0, 1]
    k = 5
    print(sol.kthCharacter(k, operations))
