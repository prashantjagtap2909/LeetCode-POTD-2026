class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str2.size();
        int m = str1.size();

        string word(m + n - 1, '?');
        
        string word2(m + n - 1, '?');
        string temp(n, '?');

        for (int i = 0; i < m; i++) {
            if (str1[i] == 'T') {
                int j = 0;
                while (j < n) {
                    if (word[j + i] != '?') {
                        if (str2[j] != word[j + i])
                            return "";
                    }
                    word[j + i] = str2[j];
                    j++;
                }
            }
        }

        for (int i=0; i<word.size(); i++) {
            if (word[i] == '?'){
                word[i] = 'a';
                word2[i] = 'a';
            }
        }

        for (int i = 0; i < m; i++) {
            if (str1[i] == 'F') {

                bool match = true;
                for (int j = 0; j < n; j++) {
                    if (word[i + j] == '?' || word[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    for (int j = n-1; j >=0; j--) {
                        if (word[i + j] == str2[j]) {
                            if(word2[i+j]!='?'){
                                word[i + j] = (str2[j] == 'a') ? 'b' : 'a';
                                match = false;
                                break;
                            }
                        }
                    }
                    if(match) return "";
                }
            }
        }


        return word;
    }
};
