class Solution {
public:
    int INF = 1e8;

    void fillFloydWarshall(vector<vector<int>> &dist) {
        for (int via = 0; via < 26; via++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][via] == INF || dist[via][j] == INF) continue;
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
    }

    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {

        int sLen = source.length();
        int n = original.size();

        vector<vector<int>> dist(26, vector<int>(26, INF));

        for (int i = 0; i < 26; i++)
            dist[i][i] = 0;

        // Initialize direct conversions
        for (int i = 0; i < n; i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], cost[i]);
        }

        // Floyd–Warshall
        fillFloydWarshall(dist);

        long long minCost = 0;

        for (int i = 0; i < sLen; i++) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';

            if (u == v) continue;
            if (dist[u][v] == INF) return -1;

            minCost += dist[u][v];
        }

        return minCost;
    }
};
