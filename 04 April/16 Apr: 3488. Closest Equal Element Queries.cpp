class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        // store indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> best(n, INT_MAX);

        // process each value group
        for (auto &it : mp) {
            vector<int> &list = it.second;
            int size = list.size();

            if (size == 1) {
                best[list[0]] = -1;
                continue;
            }

            for (int i = 0; i < size; i++) {
                int curr = list[i];

                int prev = list[(i - 1 + size) % size];
                int next = list[(i + 1) % size];

                int distPrev = abs(curr - prev);
                distPrev = min(distPrev, n - distPrev);

                int distNext = abs(curr - next);
                distNext = min(distNext, n - distNext);

                best[curr] = min(distPrev, distNext);
            }
        }

        vector<int> ans;
        for (int q : queries) {
            ans.push_back(best[q]);
        }

        return ans;
    }
};
