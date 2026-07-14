class Solution {
public:
    static inline int gcd[201][201];
    void pre_gcd(){
        if(gcd[2][4]==2)
            return;
        for(int g1=0;g1<=200;++g1)
            for(int g2=0;g2<=200;++g2)
                gcd[g1][g2]=__gcd(g1,g2);
    }
    int subsequencePairCount(vector<int>&A){
        int n=A.size(),mod=1e9+7;
        pre_gcd();
        vector dp(2,vector(201,vector(201,0)));
        for(int g=0;g<=200;++g)
            dp[n&1][g][g]=1;
        for(int i=n-1;~i;--i){
            for(int g1=0;g1<=200;++g1){
                for(int g2=0;g2<=200;++g2){
                    dp[i&1][g1][g2]=dp[(i+1)&1][g1][g2];
                    dp[i&1][g1][g2]=(dp[i&1][g1][g2]+dp[(i+1)&1][gcd[g1][A[i]]][g2])%mod;
                    dp[i&1][g1][g2]=(dp[i&1][g1][g2]+dp[(i+1)&1][g1][gcd[g2][A[i]]])%mod;
                }
            }
        }
        return dp[0][0][0]-1;
    }
};
