class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        bitset<101> hasQ=1;// set 0th bit on
        int qMax=0;
        for(int x: nums){
            auto [q, r]=div(x, k);
            if (r==0){
                hasQ[q]=1;
                qMax=max(q, qMax);
            }
        }
        auto A=bit_cast<array<uint64_t, 2>>(hasQ);
        int q0=countr_one(A[0]); 
        if (q0<64) return q0*k;
        int q1=countr_one(A[1]);
        return (q1+64)*k;
    }
};
