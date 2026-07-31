class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        for (char c : word)
            freq[c - 'a']++;

        int ans = 0;
        int assigned = 0;

        while (true) {
            int mx = 0, idx = -1;

            for (int i = 0; i < 26; i++) {
                if (freq[i] > mx) {
                    mx = freq[i];
                    idx = i;
                }
            }

            if (idx == -1) break;

            ans += mx * (assigned / 8 + 1);
            freq[idx] = 0;
            assigned++;
        }

        return ans;
    }
};
