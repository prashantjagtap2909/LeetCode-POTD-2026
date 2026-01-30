class Solution {
public:
    long long minimumCost(
        string source,
        string target,
        vector<string>& original,
        vector<string>& changed,
        vector<int>& cost
    ) {
        int n = source.length();
        unordered_map<string, int> strToId;
        int idCounter = 0;

        // Map strings to unique IDs
        for (const string& s : original)
            if (!strToId.count(s)) strToId[s] = idCounter++;
        for (const string& s : changed)
            if (!strToId.count(s)) strToId[s] = idCounter++;

        long long INF = 1e15;
        vector<vector<long long>> dist(
            idCounter,
            vector<long long>(idCounter, INF)
        );

        for (int i = 0; i < idCounter; ++i)
            dist[i][i] = 0;

        // Direct transformations
        for (int i = 0; i < original.size(); ++i) {
            int u = strToId[original[i]];
            int v = strToId[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // Floyd–Warshall
        for (int k = 0; k < idCounter; ++k)
            for (int i = 0; i < idCounter; ++i)
                for (int j = 0; j < idCounter; ++j)
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(
                            dist[i][j],
                            dist[i][k] + dist[k][j]
                        );

        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        vector<int> lengths;
        for (const string& s : original)
            lengths.push_back(s.length());
        sort(lengths.begin(), lengths.end());
        lengths.erase(unique(lengths.begin(), lengths.end()), lengths.end());

        for (int i = 0; i < n; ++i) {
            if (dp[i] == INF) continue;

            // Match single character
            if (source[i] == target[i])
                dp[i + 1] = min(dp[i + 1], dp[i]);

            // Try substring transformations
            for (int len : lengths) {
                if (i + len > n) break;

                string subS = source.substr(i, len);
                string subT = target.substr(i, len);

                if (subS == subT)
                    dp[i + len] = min(dp[i + len], dp[i]);

                if (strToId.count(subS) && strToId.count(subT)) {
                    int u = strToId[subS];
                    int v = strToId[subT];
                    if (dist[u][v] < INF)
                        dp[i + len] = min(
                            dp[i + len],
                            dp[i] + dist[u][v]
                        );
                }
            }
        }

        return dp[n] >= INF ? -1 : dp[n];
    }
};
