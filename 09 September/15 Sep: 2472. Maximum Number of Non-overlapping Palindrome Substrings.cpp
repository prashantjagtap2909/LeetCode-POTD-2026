class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size(), ans = 0, end = -1;
        for(int i = 0; i < n; i++){
            for(int l : {i - 1, i}){
                int r = i;
                while(l >= 0 && r < n && s[l] == s[r]){
                    if(r - l + 1 >= k && l > end){
                        ans++;
                        end = r;
                        break;
                    }
                    l--, r++;
                }
            }
        }
        return ans;
    }
};
