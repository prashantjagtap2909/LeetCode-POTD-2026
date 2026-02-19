class Solution {
public:
    int countBinarySubstrings(string s) {
        const int len = s.size();
        int count = 0;
        char prev = 'N'; char cur = s[0];
        int prev_count = 0; int cur_count = 1;
        for(int i=1;i<len;++i){
            if(s[i]!=cur){
                count += min(cur_count,prev_count);
                prev_count = cur_count;
                prev = cur;
                cur = s[i];
                cur_count = 1;
                continue;
            }
            else{
                ++cur_count;
            }
        }
        count += min(cur_count,prev_count);
        return count;
    }
};
