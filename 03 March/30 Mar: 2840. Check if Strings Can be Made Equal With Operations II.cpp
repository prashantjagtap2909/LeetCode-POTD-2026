class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> s1Even(26, 0), s1Odd(26, 0);
        vector<int> s2Even(26, 0), s2Odd(26, 0);
        
        for (int i = 0; i < s1.length(); i++) {
            if (i % 2 == 0) {
                s1Even[s1[i] - 'a']++;
                s2Even[s2[i] - 'a']++;
            } else {
                s1Odd[s1[i] - 'a']++;
                s2Odd[s2[i] - 'a']++;
            }
        }
        
        return (s1Even == s2Even) && (s1Odd == s2Odd);
    }
};
