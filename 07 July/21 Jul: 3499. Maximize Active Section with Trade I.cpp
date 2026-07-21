class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        // counts of zeros in blocks
        vector<int> zeros;
        int run = 0;
        for (char c : s)
            if (c == '0') ++run;
            else if (run) zeros.push_back(exchange(run, 0));
        if (run) zeros.push_back(run);

        // max zeros in two consecutive blocks
        int maxzeros = 0;
        for (int i = 1; i < zeros.size(); ++i)
            maxzeros = max(maxzeros, zeros[i - 1] + zeros[i]);

        return ranges::count(s, '1') + maxzeros;
    }
};
