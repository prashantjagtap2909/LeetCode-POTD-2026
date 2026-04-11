class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> positions;
        
        for (int i = 0; i < nums.size(); i++) {
            positions[nums[i]].push_back(i);
        }
        
        int ans = INT_MAX;
        
        for (auto& entry : positions) {
            vector<int>& idx = entry.second;
            
            if (idx.size() < 3) continue;
            
            for (int i = 0; i + 2 < idx.size(); i++) {
                int distance = 2 * (idx[i + 2] - idx[i]);
                ans = min(ans, distance);
            }
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};
