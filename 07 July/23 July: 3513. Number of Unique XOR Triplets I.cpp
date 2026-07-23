class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const unsigned n=nums.size();
        return (n<3)?n:1<<(32-countl_zero(n));
    }
};
