constexpr int N=3e5;
int last[N]; 
class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        const int n1=word1.size(), n2=word2.size();
        memset(last, -1, n2*sizeof(int)); 
        last[n2]=n1;
        for (int i=n2-1, j=n1-1; i>=0; i--) {
            const char c2=word2[i];
            while (j>=0 && c2!=word1[j]) j--;
            if (j<0) break;
            last[i]=j--;
        }
        
        vector<int> ans(n2);
        bool skip=0;
        int j=0; // index in word2
        
        for (int i=0; i<n1 && j<n2; i++) {
            const bool same=(word1[i]==word2[j]);
            const bool can_change=(!skip && i<last[j+1]);
            
            if (same | can_change) {
                ans[j++]=i;
                skip|=!same;
            }
        }
        
        return (j==n2)?ans:vector<int>();
    }
};
