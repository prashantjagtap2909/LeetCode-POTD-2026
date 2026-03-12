class Solution {

    public int maxStability(int n, int[][] edges, int k) {
        int low = 1, high = 200000, ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (canBuild(n, edges, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }

    private boolean canBuild(int n, int[][] edges, int k, int threshold) {
        UnionFind uf = new UnionFind(n);
        int edgesUsed = 0;
        int upgrades = 0;

        for (int[] e : edges) {
            if (e[3] == 1) {
                int u = e[0], v = e[1], s = e[2];

                if (s < threshold) return false;
                if (!uf.union(u, v)) return false;

                edgesUsed++;
            }
        }

        for (int[] e : edges) {
            if (e[3] == 0) {
                int u = e[0], v = e[1], s = e[2];

                if (s >= threshold && uf.union(u, v)) {
                    edgesUsed++;
                }
            }
        }

        for (int[] e : edges) {
            if (e[3] == 0) {
                int u = e[0], v = e[1], s = e[2];

                if (s < threshold && 2 * s >= threshold && uf.union(u, v)) {
                    upgrades++;
                    edgesUsed++;
                }
            }
        }

        return edgesUsed == n - 1 && upgrades <= k;
    }

    static class UnionFind {
        int[] parent, rank;

        UnionFind(int n) {
            parent = new int[n];
            rank = new int[n];

            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);

            return parent[x];
        }

        boolean union(int a, int b) {
            int pa = find(a), pb = find(b);

            if (pa == pb) return false;

            if (rank[pa] < rank[pb])
                parent[pa] = pb;
            else if (rank[pb] < rank[pa])
                parent[pb] = pa;
            else {
                parent[pb] = pa;
                rank[pa]++;
            }

            return true;
        }
    }
}
