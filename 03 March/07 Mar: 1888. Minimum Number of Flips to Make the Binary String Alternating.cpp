class Solution {
public:
    int minFlips(string s) {
        string alt1 = "", alt2 = "";
        bool flag = true;

        int cnt1 = 0, cnt2 = 0;
        int miniAns = INT_MAX;

        for(int i = 0; i < 2 * s.length(); i++){
            if(flag){
                alt1.push_back('1');
                alt2.push_back('0');
            }else{
                alt1.push_back('0');
                alt2.push_back('1');
            }
            flag = !flag;
        }

        int windowSize = s.length();
        string newStr = s + s;
        
        for(int i = 0; i < windowSize; i++){
            if(alt1[i] != s[i]) cnt1++;
            if(alt2[i] != s[i]) cnt2++;
        }

        miniAns = min(cnt1, cnt2);

        int start = 0;

        for(int end = windowSize; end < newStr.length(); end++){
            
            if(alt1[start] != newStr[start]) cnt1--;
            if(alt2[start] != newStr[start]) cnt2--;

            start++;

            if(alt1[end] != newStr[end]) cnt1++;
            if(alt2[end] != newStr[end]) cnt2++;

            miniAns = min({miniAns, cnt1, cnt2});
        }

        return miniAns;
    }
};
