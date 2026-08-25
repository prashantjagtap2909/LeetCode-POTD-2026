class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        bitset<101> hasQ=1;
        int qMax=0;
        for(int x: nums){
            auto [q, r]=div(x, k);
            if (r==0){
                hasQ[q]=1;
                qMax=max(q, qMax);
    }
};
