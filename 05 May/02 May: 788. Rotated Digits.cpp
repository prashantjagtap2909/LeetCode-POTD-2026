class Solution {
public:
    vector<int> vec;
    vector<vector<vector<int>>> dp;
    int solve(int index , int lower, int change ){
        if(index == vec.size()) return change;
        if(dp[index][lower][change]!=-1) return dp[index][lower][change];
        int ans = 0 ;        
        for(int d : {0, 1, 2 ,5 , 6 , 8 , 9 }) {
            bool c = change or (d != 1 and d != 8 and d!= 0);
            if(lower) { // can be anything
                ans += solve(index + 1 , lower , c);
            }else { // only if d <= vec[index]
                if(d <= vec[index]) {
                    ans += solve(index + 1 , d < vec[index] , c);
                }
            }
        }
        return dp[index][lower][change]= ans;
    }
    int rotatedDigits(int n) {
        while(n) {
            vec.push_back(n%10);
            n/=10;
        }
        reverse(vec.begin(), vec.end());
        dp.resize(vec.size(),vector<vector<int>> (2, vector<int> (2,-1)));
        return solve(0 , 0 , 0 );
    }
};
