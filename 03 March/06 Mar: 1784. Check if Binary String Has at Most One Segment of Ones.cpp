class Solution {
public:
    bool checkOnesSegment(string s) {
        bool seenZero = false;

        for(char c : s){
            if(c == '0'){
                seenZero = true;
            }
            else if(seenZero){
                return false;
            }
        }

        return true;
    }
};
