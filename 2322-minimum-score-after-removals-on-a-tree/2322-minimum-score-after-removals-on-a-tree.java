class Solution {
    private int totalXor, subtreeXor, minScore;
    private int n;
    private int[] nums;
    private List<Integer>[] graph;

    public int minimumScore(int[] nums, int[][] edges) {
        this.n = nums.length;
        this.nums = nums;
        graph = new List[n];
        for (int i = 0; i < n; i++) graph[i] = new ArrayList<>();

        for (int[] e : edges) {
            graph[e[0]].add(e[1]);
            graph[e[1]].add(e[0]);
        }

        for (int v : nums) totalXor ^= v;
        minScore = Integer.MAX_VALUE;

        for (int u = 0; u < n; u++) {
            for (int v : graph[u]) {
                // Try removing edge u–v
                subtreeXor = dfsXor(u, -1, v);
                dfsScore(u, -1, v);
            }
        }
        return minScore;
    }

    private int dfsXor(int u, int parent, int blocked) {
        int xor = nums[u];
        for (int w : graph[u]) {
            if (w != parent && w != blocked) xor ^= dfsXor(w, u, blocked);
        }
        return xor;
    }

    private int dfsScore(int u, int parent, int blocked) {
        int cur = nums[u];
        for (int w : graph[u]) {
            if (w != parent && w != blocked) {
                int sub = dfsScore(w, u, blocked);
                cur ^= sub;
                int xor1 = sub;
                int xor2 = subtreeXor ^ xor1;
                int xor3 = totalXor ^ subtreeXor;
                int max = Math.max(xor1, Math.max(xor2, xor3));
                int min = Math.min(xor1, Math.min(xor2, xor3));
                minScore = Math.min(minScore, max - min);
            }
        }
        return cur;
    }
}
