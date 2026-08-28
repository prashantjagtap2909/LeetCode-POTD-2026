class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();
        vector<int> hsh(26, 0);

        for (int i = 0; i < n; i++) {
            hsh[s[i] - 'a']++;
        }

        
        string ans = s;
        int odd = 0;
        for (int i = 0; i < 26; i++) {
            if (hsh[i] % 2 != 0) {
                odd++;
            
                ans[n / 2] = char('a' + i);
            }

            hsh[i] /= 2;
        }

        if (odd > 1) {
            return "";
        }

        int p = 0;
        while (p < n / 2 && hsh[target[p] - 'a']) {
            hsh[target[p] - 'a']--;
            p++;
        }

        int start = min(n - 1, p);
        for (int i = start; i >= 0; i--) {

            if (i == n / 2) {
                for (int j = 0; j < n / 2; j++) {
                    ans[j] = target[j];
                    ans[n - 1 - j] = target[j];
                }

                if (ans > target) {
                    return ans;
                }
                continue;
            }

           
            int b = target[i] - 'a';

            
            if (i < p) {
                hsh[b]++;
            }

           
            int idx = -1;
            for (int c = b + 1; c < 26; c++) {
                if (hsh[c]) {
                    hsh[c]--;
                    idx = c;
                    break;
                }
            }
         
            if (idx == -1) {
                continue;
            }
            
            for (int j = 0; j < i; j++) {
                ans[j] = target[j];
            }
           
            ans[i] = char('a' + idx);

           
            int k = i + 1;

            for (int c = 0; c < 26; c++) {
                while (k < n && hsh[c]) {
                    ans[k] = char(c + 'a');
                    k++;
                    hsh[c]--;
                }
            }

            for (int j = 0; j < n / 2; j++) {
              ans[n - 1 - j] = ans[j];
            }

            return ans;
        }

        // No valid palindrome greater than target
        return "";
    }
};
